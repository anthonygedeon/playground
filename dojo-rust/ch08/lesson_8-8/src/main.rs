fn main() {
    let mut v = Vec::new();
    v.push(String::from("hello")); // works with strings
    for i in &v { // can still loop over a empty vector
        println!("{}", i);
    }
}
