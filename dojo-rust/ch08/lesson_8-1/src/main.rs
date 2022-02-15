fn main() {
    // Vec is a struct that has an associated function called new
    // This has similar style of OOP...
    // ::new is like the constructor
    // let v: Vec<i32> = Vec::new(1, 2, 3); -> this doesn't work
    
    // I have to annotate the type because Rust doesn't know at compile time on waht I want to push into this struct
    let v1: Vec<i32> = Vec::new();
    // since I'm mutating it I have to use mut
    let mut v2: Vec<String> = Vec::new();

    v2.push(String::from("1"));
    println!("{:?} {:?}", v1, v2);
}
