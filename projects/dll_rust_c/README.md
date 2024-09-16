Run

```bash
cargo build --release
```

Then compile the C program

```bash
gcc src_c/main.c -o main -L./target/release -ldll
```

Lastly run the executable

```bash
./main
```
