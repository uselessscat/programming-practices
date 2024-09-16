// siempre se declara el tipo
const PI: f32 = 3.141592;

fn main() {
    // constante
    println!("constante {}", PI);

    // variable inmutable
    let a: i32 = 123;
    println!("variable inmutable {}", a);

    // variable mutable
    let mut b: i32 = 3;
    println!("variable mutable {}", b);
    b = 15;
    println!("variable mutable asignacion {}", b);

    // shadowing 
    let a: i32 = 456;
    println!("variable inmutable sobreescrita {}", a);

    // specify type
    let c = 123i32;
    println!("variable inmutable especificando tipo {}", c);
}
