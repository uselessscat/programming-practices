fn return_tuple () -> (i32, i32) {
    return (1, 2)
}

struct Point {
    x: i32,
    y: i32
}

fn main(){
    // Destructuring an array
    let arr = [1, 2, 3, 4, 5];

    let [a, b, ..] = arr;
    println!("a: {}", a);

    // Destructuring a tuple
    let (a, ..) = return_tuple();
    println!("a: {}", a);

    // Destructuring a struct
    let point = Point { x: 1, y: 2 };

    let Point { x: x1, .. } = point;
    println!("x1: {}", x1);


    let my: i32 = {1};
}