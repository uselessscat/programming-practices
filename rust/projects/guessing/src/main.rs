use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Adivina el numero!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    loop {
        println!("Ingresa un numero.");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("No se pudo leer la linea");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("probaste: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Muy pequeño!"),
            Ordering::Greater => println!("Muy grande!"),
            Ordering::Equal => {
                println!("Ganaste!");
                break;
            }
        }
    }
}