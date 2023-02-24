fn main() {
    let list = vec![1, 2, 3, 4];
    println!("Before defining closure: {:?}", list);
    
    // capturing list and lets the closure move list so it no longer borrows list
    let foo = move || println!("From closure: {:?}", list);

    println!("Before calling closure: {:?}", list);
    foo();
    println!("After calling closure: {:?}", list);
}
