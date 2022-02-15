fn main() {
    let mut v = vec![100, 32, 56];
    for i in &mut v {
        *i += 50;
    }
    v.push(12);
    println!("{:?}", v);
}
