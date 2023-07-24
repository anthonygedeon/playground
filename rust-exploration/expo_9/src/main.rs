use std::thread;
use std::time::Duration;

fn main() {
    let handle1 = thread::Builder::new().name("A".to_string()).spawn(move || {
        fn rec() {
            rec()
        }
        rec();
        println!(
            "Highly-intensive CPU work from {:?} Thread",
            thread::current().name().unwrap()
        );
    });

    let handle2 = thread::Builder::new().name("B".to_string()).spawn(move || {
        println!(
            "Highly-intensive CPU work from {:?} Thread",
            thread::current().name().unwrap()
        );
    });

    handle1.unwrap().join();
    handle2.unwrap().join();

    // something that last long until threads can join back with the main thread

    println!("Done with Main Thread");
}
