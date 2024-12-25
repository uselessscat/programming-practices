use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    let text: Vec<_> = args[1].chars().collect();

    for i in 0..text.len() - 1 {
        for j in i + 1..text.len() {
            if &text[i] == &text[j] {
                println!("repeated char {}", &text[i]);

                return;
            }
        }
    }

    println!("all chars ar different")
}
