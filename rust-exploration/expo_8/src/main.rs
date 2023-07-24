use std::thread;

fn main() {
    let mut list_a = vec![];
    let mut list_b = vec![];

    let handle_a = thread::Builder::new().name("A".to_string()).spawn(move || {
        println!(
            "Start work on Thread {:?}",
            thread::current().name().unwrap()
        );
        list_a.push(1);
        println!("List A: {:?}", list_a);
    });

    let handle_b = thread::Builder::new().name("B".to_string()).spawn(move || {
        println!(
            "Start work on Thread {:?}",
            thread::current().name().unwrap()
        );
        list_b.push(1);
        println!("List B: {:?}", list_b);
    });

    handle_a.expect("thread failed").join();
    handle_b.expect("thread failed").join();

    println!("Main Thread Done!");
}
