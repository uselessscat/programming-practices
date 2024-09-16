use std::thread;

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    // only borrows
    let list = vec![1, 2, 3];
    println!("Before defining closure: {:?}", list);

    let only_borrows = || println!("From closure: {:?}", list);

    println!("Before calling closure: {:?}", list);
    only_borrows();
    println!("After calling closure: {:?}", list);

    // borrows mutably
    let mut list2 = vec![1, 2, 3];
    println!("Before defining closure: {:?}", list2);

    let mut borrows_mutably = || list2.push(7);

    borrows_mutably();
    println!("After calling closure: {:?}", list2);

    // take ownership
    let list3 = vec![1, 2, 3];
    println!("Before defining closure: {:?}", list3);

    thread::spawn(move || println!("From thread: {:?}", list3))
        .join()
        .unwrap();
        
    // this closure works because it is only capturing a mutable reference
    // and can be called more than once
    let mut list = [
        Rectangle { width: 10, height: 1 },
        Rectangle { width: 3, height: 5 },
        Rectangle { width: 7, height: 12 },
    ];

    let mut num_sort_operations = 0;
    list.sort_by_key(|r| {
        num_sort_operations += 1;
        r.width
    });
    println!("{:#?}, sorted in {num_sort_operations} operations", list);
}