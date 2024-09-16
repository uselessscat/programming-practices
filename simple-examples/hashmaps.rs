use std::collections::HashMap;

fn main(){
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    // accessing items in the hashmap
    let team_name = String::from("Blue");
    let score = scores.get(&team_name).copied().unwrap_or(0);

    println!("{}", score);

    // iterate over items
    for (key, value) in &scores {
        println!("{key}: {value}");
    }

    // inserting duplicated item will be overwritten
    scores.insert(String::from("Blue"), 25);
    println!("{:?}", scores);

    // if a value exist dont replace it
    scores.entry(String::from("Yellow")).or_insert(60);
    println!("{:?}", scores);
}