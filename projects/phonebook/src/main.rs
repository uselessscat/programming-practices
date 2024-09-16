use std::io;

struct Contact {
    name: String,
    phone: String,
}

fn main() {
    println!("Phonebook v1");

    let mut contacts: Vec<Contact> = Vec::new();

    loop {
        println!("Enter an option: \n 1) New record\n 2) List contacts");

        let mut option = String::new();

        io::stdin()
            .read_line(&mut option)
            .expect("Failed to read line");

        let option: u32 = match option.trim().parse() {
            Ok(opt) => opt,
            Err(_) => continue,
        };

        match option {
            1 => contacts.push(create_contact()),
            2 => list_contacts(&contacts),
            _ => println!("Unrecognized option."),
        }
    }
}

fn create_contact() -> Contact {
    let mut name = String::new();
    let mut phone = String::new();

    println!("Enter contact name:");
    io::stdin()
        .read_line(&mut name)
        .expect("Failed to read line");

    println!("Enter phone:");
    io::stdin()
        .read_line(&mut phone)
        .expect("Failed to read line");

    println!("Contact successfully created!\n");

    Contact {
        name: name.trim().to_string(),
        phone: phone.trim().to_string(),
    }
}

fn list_contacts(contacts: &Vec<Contact>) {
    println!("Contacts in the list:");

    for (i, contact) in contacts.iter().enumerate() {
        println!(
            "{}: Name : {}\n   Phone: {}",
            i, contact.name, contact.phone
        );
    }

    print!("\n")
}
