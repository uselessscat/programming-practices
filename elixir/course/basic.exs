IO.puts("Hello world from Elixir")

IO.puts("-- basic arithmetic --")
IO.puts(1 + 1)
IO.puts(1 - 1)
IO.puts(1 * 1)

# always returns a float
IO.puts(10 / 3)

IO.puts(div(10, 3))
IO.puts(rem(10, 3))

# can ignore parentheses
IO.puts div 10, 3

# alternative notations
IO.puts(0b1010)
IO.puts(0o777)
IO.puts(0x1F)

# floats are 64-bit
IO.puts(0.1)
IO.puts(0.1e-10)

IO.puts(round 1.59)
IO.puts(trunc 1.59)

IO.puts(is_integer(1))
IO.puts(is_float(1.0))
IO.puts(is_number(1.0))

IO.puts("-- boolean --")
IO.puts(true)
IO.puts(false)
IO.puts(true == false)
IO.puts(is_boolean(true))

# boolean operators are short-circuiting
IO.puts(false and raise("This error will never be raised"))
IO.puts(true or raise("This error will never be raised"))

# elixir provides nil and operators to work with it
IO.puts("-- nil --")
IO.puts(nil)
IO.puts(is_nil(nil))

# or
IO.puts(1 || true)
IO.puts(false || 11)

# and
IO.puts(nil && 13)
IO.puts(true && 17)

# not
IO.puts(!true)
IO.puts(!1)
IO.puts(!nil)

IO.puts("-- atoms --")
IO.puts(:dog)
IO.puts(is_atom(:dog))
IO.puts(:dog == :cat)

# true, false and nil are atoms that can be used without the leading colon
IO.puts(is_boolean(:true))
IO.puts(is_atom(false))

IO.puts("-- strings --")
IO.puts("hello")

# concatenation
IO.puts("hello " <> "world")

# interpolation
string = "world"
IO.puts("hello #{string}")

IO.puts(is_binary("hello"))
IO.puts(byte_size("hellö"))
IO.puts(String.length("hellö"))

IO.puts("-- operators --")
IO.puts(1 > 2)
IO.puts(1 == 1.0)
IO.puts(1 === 1.0)
