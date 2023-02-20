#![allow(unused)]
fn main() {
    use std::collections::HashMap;
    
    let mut scores = HashMap::new(); 

    scores.insert("Blue".to_string(), 10);
    scores.insert("Yellow".to_string(), 50);
    scores.insert("Blue".to_string(), 60);
    scores.insert("Black".to_string(), 60);

    scores.entry(String::from("Black")).and_modify(|v| *v += 1).or_insert(50);
    
    let team_name = String::from("Blue");
    let score = scores.get(&team_name).copied().unwrap_or(0);
        
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }
    
    dbg!(score);
    
    let mut field_name = String::from("Favorite color");
    let field_value = String::from("Blue");
    
    let mut map = HashMap::new();
    map.insert(&field_name, &field_value);
    
      let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        *map.entry(word).or_insert(0) += 1;
    }

    println!("{:?}", map);
}
