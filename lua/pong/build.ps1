# clean dir
Remove-Item dist\*

# compress the sources
Compress-Archive -Path sound, lib, assets, *.lua -CompressionLevel Optimal -DestinationPath dist\pong.zip -Force

# merge with love executable
Get-Content love\love.exe,dist\pong.zip -Enc Byte -Read 512 | Set-Content dist\pong.exe -Enc Byte

# delete zip file
Remove-Item dist\pong.zip

# copy ddl files
Copy-Item -Path love\love.dll, love\lua51.dll, love\SDL2.dll, love\OpenAL32.dll, love\mpg123.dll -Destination dist

# compress a zip to distribute
Compress-Archive -Path dist\* -CompressionLevel Optimal -DestinationPath dist\pong.zip -Force