use std::io;

fn main() {
    let fahrenheit: f32;

    loop {
        println!("Enter a Fahrenheit temperature:");

        let mut input = String::new();

        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        fahrenheit = match input.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        break;
    }

    let celcius: f32 = (fahrenheit - 32.0) * 5.0 / 9.0;

    println!("The Celcius temp is: {celcius}");
}
