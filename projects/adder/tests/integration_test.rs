use adder;

mod common;

#[test]
fn it_adds_two2() {
    common::setup();
    assert_eq!(4, adder::add_two(2));
}