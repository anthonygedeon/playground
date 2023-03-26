pub fn rotate(input: &str, key: i8) -> String {
    input
        .chars()
        .map(|c| match c {
            'A'..='Z' => todo!(),
            'a'..='z' => todo!(),
            _ => (),
        })
        .collect()
}
