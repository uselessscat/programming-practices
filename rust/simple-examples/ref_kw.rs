fn main(){

    let tupla = (String::from("Hola"), 42);
    
    match tupla {
        (ref saludo, ref numero) => {
            println!("Saludo: {}, Número: {}", saludo, numero);
            // Aquí, `saludo` es una referencia a `String` (&String)
            // y `numero` es una referencia a `i32` (&i32)
        }
    }

    // version moderna
    match &tupla {
        (saludo, numero) => {
            println!("Saludo: {}, Número: {}", saludo, numero);
        }
    }
    
}