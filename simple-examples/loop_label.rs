fn main() {
    let mut counter = 0;

    'outer: loop {
        counter += 1;
        println!("outer: {}", counter);

        loop {
            println!("inner");
            if counter == 3 {
                break 'outer;
            }
            break;
        }

        if counter >= 5 {
            break;
        }
    }

    println!("end");
}