fn main() {
    let mut v1 = Vec::new();
    let mut v2 = vec![];

    println!("{:?}", v1);

    v1.push(32); // weird, I don't have to annotate the type anymore because Rust can now infer what types I will be using. Let's try to break this

    println!("{:?}", v1);
    v2.push(21);

    println!("{:?}", v2);

}
