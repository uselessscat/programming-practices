// trait with associated type
trait IteratorAT {
    type Item;
    fn next(&mut self) -> Option<Self::Item>;
}

struct CounterU32 {
    count: u32,
}

impl IteratorAT for CounterU32 {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

// generic
trait IteratorG<T> {
    fn next(&mut self) -> Option<T>;
}

struct CounterG {
    count: i32,
}

impl IteratorG<i32> for CounterG {
    fn next(&mut self) -> Option<i32> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

fn main(){
    let mut counter = CounterU32 { count: 0 };

    println!("{:?}", counter.next());

    let mut counter = CounterG { count: 0 };

    println!("{:?}", counter.next());
}