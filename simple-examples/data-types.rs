// tuple struct
struct Color(i32, i32, i32);


struct Person {
    name: String,
    last_name: String,
    age: i8,
}

fn main() {
    let a: i32 = 5;
    let b: i32 = 18;

    let c: i32 = a + b;

    println!("i32 {}", c);

    // flotantes
    let d: f32 = 4.4;

    // para poder operar hay que convertir explicitamente los tipos de datos
    let e: f64 = f64::from(c) + (d as f64);

    println!("f64 {}", e);

    // booleanos
    let boolean: bool = true && false;

    println!("bool {}", boolean);

    // caracteres
    let z: char = 'z';
    // en rust los caracteres son unicode
    let gato: char = '😻';

    println!("chars {} {}", z, gato);

    // tuplas
    let mi_tupla: (i32, f32, char) = (20, 4.4, 'A');
    // acceder con <tupla>.n
    println!("tuple {} {} {}", mi_tupla.0, mi_tupla.1, mi_tupla.2);

    // destructuring
    let (x, y, z) = mi_tupla;
    println!("tuple {} {} {}", x, y, z);

    // arrays
    // se inicializa el array de strings
    let mi_array: [&str; 2] = ["hola", "mundo"];

    // se inicializa el array con cinco 0's
    let mi_array2: [i32; 5] = [0; 5];

    println!("array1 {}", mi_array[1]);
    println!("array2 {}", mi_array2[4]);
    println!("array2 len {}", mi_array2.len());

    // struct
    let person1 = Person {
        name: String::from("Robert"),
        last_name: String::from("Callaghan"),
        age: 30,
    };

    println!("name {}", person1.name);

    let person2 = Person {
        name: String::from("Peter"),
        ..person1
    };

    // this should return error if we use person1.name because of ownership
    println!(
        "name {} last_name {} age {}",
        person2.name, person2.last_name, person2.age
    );

    println!("test copy trait {}", person1.age);

    // tuple struct
    let color = Color(123, 200, 190);

    let Color(r, g, b) = color;
    println!("r {} g {} b {}", r, g, b);
    println!("r {} g {} b {}", color.0, color.1, color.2);
}
