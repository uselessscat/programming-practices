use std::fmt;

struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

impl<T: fmt::Display + PartialOrd> Point<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
        } else {
            println!("The largest member is y = {}", self.y);
        }
    }
}

trait Convert<T> {
    fn convert(&self) -> T;
}

impl Convert<f32> for i32 {
    fn convert(&self) -> f32 {
        *self as f32
    }
}

// make point implement convert 
impl Convert<f32> for Point<i32> {
    fn convert(&self) -> f32 {
        self.x as f32
    }
}

impl fmt::Display for Point<i32> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Point({}, {})", self.x, self.y)
    }
}
    
// implement to string for point
// impl ToString for Point<i32> {
//     fn to_string(&self) -> String {
//         format!("Point {{ x: {}, y: {} }}", self.x, self.y)
//     }
// }

// impl<T: Display> Point<T> {
//     fn to_string(&self) -> String {
//         format!("Point {{ x: {}, y: {} }}", self.x, self.y)
//     }
// }

fn main() {
    let p = Point::new(1, 2);
    let x_converted: f32 = p.x.convert();
    let y_converted: f32 = p.y.convert();

    println!("p.x = {}, p.y = {}", p.x, p.y);
    println!("x = {}, y = {}", x_converted, y_converted);
    p.cmp_display();

    let p = Point::new(1, 2);
    let p_converted: f32 = p.convert();
    println!("p.x = {}, p.y = {}, p converted = {}", p.x, p.y, p_converted);
    println!("p = {}", p.to_string());
}