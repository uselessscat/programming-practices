struct ImportantExcerpt<'a> {
    part"../simple-examples": &'a str,
}

use std::fmt::Display;

fn longest_with_an_announcement<'a, T>(
    x: &'a str,
    y: &'a str,
    ann: T,
) -> &'a str
where
    T: Display,
{
    println!("Announcement! {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let string1 = String::from("abcd");
    let string2: &'static str = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);

    // la referencia a novel no se destruye hasta que ImportantExcerpt salga del contexto
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let i = ImportantExcerpt {
        part: first_sentence,
    };

    longest_with_an_announcement(string1.as_str(), string2, 99);
}

// sin la anotacion de lifetime el compilador no sabe que lifetime (de x o y) debe usar para el tipo de retorno
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}