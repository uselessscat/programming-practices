use std::ops::Deref;

// trying to emulate Box<T>
struct MyBox<T>(T);
impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

fn hello(name: &str) {
    println!("Hello, {name}!");
}

fn main() {
    let x: i32 = 5;
    let y: &i32 = &x;
    let z = Box::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);
    assert_eq!(5, *z);

    let y = MyBox::new(x);
    assert_eq!(5, *y);

    // deref coercion
    // When the Deref trait is defined for the types involved,
    // Rust will analyze the types and use Deref::deref as many
    // times as necessary to get a reference to match the parameter’s type.
    let m = MyBox::new(String::from("Rust"));
    hello(&m); // MyBox -> String -> &str
}