#[derive(Debug)]
enum IpAddrKind {
    V4,
    V6,
}

#[derive(Debug)]
struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

#[derive(Debug)]
enum IpAddr2 {
    V4(String),
    V6(String),
}

#[derive(Debug)]
enum IpAddr3 {
    V4(u8, u8, u8, u8)
}
fn route(_ip_kind: IpAddrKind) {}

enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

#[derive(Debug)]
struct MyStruct {
    message: String,
}

#[derive(Debug)]
enum StructContainer {
    Container(MyStruct),
}

#[derive(Debug)]
enum MyEnum {
    Value(u32)
}

fn main (){
    let _four = IpAddrKind::V4;
    let _six = IpAddrKind::V6;

    route(IpAddrKind::V4);
    route(IpAddrKind::V6);

    let home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1"),
    };

    let loopback = IpAddr {
        kind: IpAddrKind::V6,
        address: String::from("::1"),
    };
    println!("{:?} {:?}", home, loopback);

    let home = IpAddr2::V4(String::from("127.0.0.1"));
    let loopback = IpAddr2::V6(String::from("::1"));
    println!("{:?} {:?}", home, loopback);

    let home = IpAddr3::V4(127, 0, 0, 1);
    println!("{:?}", home);

    // valores para Option<T>
    let _some_number = Some(5);
    let _some_char = Some('e');

    let _absent_number: Option<i32> = None;

    let my_struct = MyStruct {
        message: String::from("Hello, world!"),
    };

    let message = StructContainer::Container(my_struct);

    println!("{:?}", message);

    // use enum as initializer
    let values: Vec<_> = (0u32..10).map(MyEnum::Value).collect();
    println!("{:?}", values);
}