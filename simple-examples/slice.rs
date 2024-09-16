fn main(){
    let str = String::from("hello world");

    let first_word_loc = first_word(&str);

    println!("{}",first_word_loc);

    let first_word_slc = first_word_slice(&str);

    println!("{}",first_word_slc);
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}

fn first_word_slice(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    // devuelve el string completo
    &s[..]
}