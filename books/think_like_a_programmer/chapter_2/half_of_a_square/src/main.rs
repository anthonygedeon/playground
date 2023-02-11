fn main() {
    (1..5).rev()
        .for_each(|i| println!("{}","#".repeat(i)));
}
