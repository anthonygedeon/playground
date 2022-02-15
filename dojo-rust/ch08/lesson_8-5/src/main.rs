fn main() {
    let mut v1 = vec![1, 2, 3, 4, 5];

    // let third = &v1.clone(); 
    let third = &v1[2]; // why am I using a reference
    v1.push(1); // why doesn't this work?

    println!("{:?}", third);

    match v1.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element."),
    }
}
