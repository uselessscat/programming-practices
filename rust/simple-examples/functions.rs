// funcion principal, el programa siempre empieza aca
fn main() {
    // estos son "statements" o declaraciones, estos no devuelven un valor
    let a: i32 = 1;

    // shadowing oculta variables
    // una declaracion puede contener expresiones como 2 - 1
    let a: i32 = 2 - a;

    // los bloques, las llamadas a funciones y las operaciones son "expressions"
    let b: i32 = {
        let num = 9; // una declaracion

        num // sin el ; esto es una expresion
    };
    
    let result = sum(a, b);

    println!("{}", result);

    // shadowing nuevamente
    let result = result + sum2(a, b);

    println!("{}", result);

    // debido a que "main()" no declara tipo de retorno, 
    // podemos ignorar el ; al final por que el println_aux devuelve "()" vacio
    println_aux(pi())
}

// declaracion de funcion. para los parametros se declaran siempre los tipos
// si devuelve valor, se debe declarar el tipo con ->
fn sum(a: i32, b: i32) -> i32 {
    return a + b;
}

fn sum2(a: i32, b: i32) -> i32 {
    // esto está en forma de expresion
    // si se agrega el ; se transforma en un "statement" o declaracion
    a + b
}

// usando la propiedad anterior, podemos escribir funciones cortas
fn pi() -> f32 { 3.141592 }

// el retorno vacio se declara como ()
fn println_aux(a: f32) -> () {
    println!("{}", a)
}