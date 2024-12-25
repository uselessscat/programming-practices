defmodule FileCompressor do
  def compress_file(input_path, output_path) do
    with {:ok, data} <- File.read(input_path) do
      compressed_data = :ezstd.compress(data)

      File.write(output_path, compressed_data)
    else
      {:error, reason} -> IO.puts("Error leyendo el archivo: #{reason}")
    end
  end

  def decompress_file(input_path, output_path) do
    with {:ok, data} <- File.read(input_path) do
      {:ok, decompressed_data} = :ezstd.decompress(data)
      File.write(output_path, decompressed_data)
    else
      {:error, reason} -> IO.puts("Error leyendo el archivo: #{reason}")
    end
  end
end
