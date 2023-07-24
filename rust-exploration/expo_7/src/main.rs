#![allow(unused)]
fn main() {
    let h1 = std::thread::spawn(|| {
        println!("hello");
        std::thread::sleep(std::time::Duration::from_secs(10));
    });

    let h2 = std::thread::spawn(|| {
        println!("hello");
        std::thread::sleep(std::time::Duration::from_secs(10));
    });

    let h3 = std::thread::spawn(|| {
        println!("hello");
        std::thread::sleep(std::time::Duration::from_secs(10));
    });

    h1.join();
    h2.join();
    h3.join();

    println!("world");

    loop {}
}
