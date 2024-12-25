use std::io;

fn main() {
    let mut nth = String::new();

    io::stdin()
        .read_line(&mut nth)
        .expect("Failed to read line");

    let nth: i32 = match nth.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    let number: i32 = fibonacci(nth);

    println!("the nth number of fibbonacci is {number}")
}

fn fibonacci(nth: i32) -> i32 {
    match nth {
        0 => 0,
        1 => 1,
        _ => fibonacci(nth - 1) + fibonacci(nth - 2),
    }
}
