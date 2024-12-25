fn main() {
    let s = "Hola";

    let x = s;

    // esto funciona por que s está en el stack
    println!("{}", s);
    takes_ownership(x);
    println!("{}", x);

    // ---------------------------------------------
    let s = String::from(s);

    let x = s;

    println!("{}", x);
    // esto da error de compilacion
    //println!("{}", s);
    takes_ownership_string(x);

    // esto tambien da error
    //println!("{}", x);

    // ----------------------------------------------
    let a = gives_ownership();

    println!("{}", a);

    let p = takes_and_gives_back(a);

    println!("{}", p);

    // -----------------------------------------------
    // si queremos usar un valor sin tomar el ownership, usamos referencias
    // envian un referencia inmutable a la estructura de string
    let len = calculate_lenght(&p);

    println!("{} {}", p, len);

    // -----------------------------------------------
    // mutable references
    let mut s = String::from("que pasa?");
    
    change(&mut s);

    println!("{}", s);

    // ------------------------------------------------
    // las referencias mutables tienen la restriccion de ser unicas en el mismo ambito
    let mut s = String::from("hello");

    let r1 = &mut s;
    //let r2 = &mut s; // esto da error de compilacion 
    // println!("{}, {}", r1, r2);

    // -----------------------------------------------
    // sepueden crear nuevos ambitos permitiendo crear multiples referencias
    let mut s = String::from("hello");

    {
        let r1 = &mut s;
    }

    let r2 = &mut s;
    println!("{}", r2);
}

fn takes_ownership(s: &str) {
    println!("{}", s);
}

fn takes_ownership_string(s: String) {
    println!("{}", s);
}

fn gives_ownership() -> String {
    let s = String::from("Hola que hace");
    // devolver la referencia a "s"
    s
}

fn takes_and_gives_back(s: String) -> String {
    s
}

// a tener punteros como parametros se le llama "borrowing"
fn calculate_lenght(s: &String) -> usize {
    s.len()
}

fn change(s: &mut String) {
    s.push_str(" wena wena");
}
