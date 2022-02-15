fn main() {
    let v1: Vec<i32> = vec![]; // I need to annotate the macro
    let v2 = vec![1, 2, 3];

    // this doesn't work
    // Rust evaluates from left to right when trying to figure out the main type of a vector
    // let v3 = vec![String::from("hello world"), 1];

    println!("{:?} {:?}", v1, v2);
}
