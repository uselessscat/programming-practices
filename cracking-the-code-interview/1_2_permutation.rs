use std::env;
use std::collections::HashMap;

fn main(){
    let mut map = HashMap::new();

    let args: Vec<String> = env::args().collect();

    let text_1: Vec<_> = args[1].chars().collect();
    let text_2: Vec<_> = args[2].chars().collect();

    for c in text_1 {
        let count = map.entry(c).or_insert(0);
        *count += 1;
    }

    for c in text_2 {
        let count = map.entry(c).or_insert(0);
        *count -= 1;
    }

    for (_, v) in map {
        if v != 0 {
            println!("not permutation");
            return;
        }
    }

    println!("permutation");
}