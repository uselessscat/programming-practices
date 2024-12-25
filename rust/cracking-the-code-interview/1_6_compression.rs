use std::env;
use std::vec::Vec;

fn main() {
    let args: Vec<String> = env::args().collect();
    let text: Vec<char> = args[1].chars().collect();

    if text.len() < 1 {
        return;
    }

    let mut chars: Vec<char> = Vec::new();
    let mut counts: Vec<i32> = Vec::new();

    chars.push(text[0]);
    counts.push(1);

    for c in text.into_iter().skip(1) {
        let last_char_index = chars.len() - 1;

        if chars[last_char_index] == c {
            counts[last_char_index] += 1;
        } else {
            counts.push(1);
            chars.push(c);
        }
    }

    for (r#char, count) in chars.iter().zip(counts.iter()) {
        print!("{}{}", r#char, count);
    }

    println!("");
}
