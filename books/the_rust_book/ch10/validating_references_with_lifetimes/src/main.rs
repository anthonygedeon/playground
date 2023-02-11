fn longest<'a>(x: &'a str, y: &'a str) -> &'a str  {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }
    
    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

use std::fmt::Display;

fn longest_with_an_accounement<'a, T>(
    x: &'a str,
    y: &'a str,
    ann: T,
) -> &'a str
where 
    T: Display 
{
    println!("Announcement! {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    println!("{:#?}", first_sentence);
    let i = ImportantExcerpt {
        part: first_sentence,
    };
}

