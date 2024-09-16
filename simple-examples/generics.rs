// generics en enums
enum Option<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}

// generics en struct
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    fn x(&self) -> &T {
        &self.x
    }

    fn y(&self) -> &U {
        &self.y
    }
}

impl Point<f32, f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

impl<X1, Y1> Point<X1, Y1> {
    fn mixup<X2, Y2>(self, other: Point<X2, Y2>) -> Point<X1, Y2> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

fn main() {
    let _both_integer = Point { x: 5, y: 10 };
    let both_float = Point { x: 1.1, y: 4.1 };
    let integer_and_float = Point { x: 5, y: 4.2 };

    println!("p.x = {}", integer_and_float.x());
    println!("p.y = {}", integer_and_float.y());
    println!("distance = {}", both_float.distance_from_origin());

    let p3 = both_float.mixup(integer_and_float);

    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);
}

