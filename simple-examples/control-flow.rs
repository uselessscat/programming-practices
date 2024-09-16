fn chao(){
    println!("chao");
}

fn main(){
    let var = 5;

    if var > 0 {
        println!("{}", true)
    } else {
        println!("{}", false)
    }

    // multiples expresiones
    if var > 5 {
        println!(">5")
    } else if var < 5 {
        println!("<5")
    } else {
        println!("==5")
    }

    // los if pueden devolver la expresion del bloque que corresponda 
    let r = if var > 0 { 5 } else { 6 };
    println!("{}", r);

    // podemos devolver funciones 
    let f: fn() = if var > 0 {
        fn fun(){
            println!("hola");
        }

        fun
    } else {
        chao
    };

    f();


    let mut counter = 0;
    // ciclo infinito, devolver valor unico
    let res = loop {
        if counter == 10 {
            break counter;
        }

        counter += 1;
    };

    println!("{}", res);

    // ciclo con condicion 
    counter = 0;
    while counter <= 10 {
        println!("{}", counter);
        counter += 1;
    };

    // ciclo for para recorrer iterables
    let lst: [i32; 5] = [1, 2, 3, 4, 5];
    for el in lst.iter() {
        println!("{}", el * el);
    }

    for el in 1..6 {
        println!("{}", el * el);
    }

    // match contol flow
    #[derive(Debug)]
    enum UsState {
        Alabama,
        Alaska,
        // --snip--
    }
    enum Coin {
        Penny,
        Nickel,
        Dime,
        Quarter(UsState),
    }
    
    fn value_in_cents(coin: Coin) -> u8 {
        match coin {
            Coin::Penny => {
                println!("Lucky penny!");
                1
            },
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter(state) => {
                println!("State quarter from {:?}!", state);
                25
            }
        }
    }
    let val = value_in_cents(Coin::Quarter(UsState::Alaska));

    println!("{}", val);

    // if let
    let config_max = Some(3u8);
    if let Some(max) = config_max {
        println!("The maximum is configured to be {}", max);
    }
}

