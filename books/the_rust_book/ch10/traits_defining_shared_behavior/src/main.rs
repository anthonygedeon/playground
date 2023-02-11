use std::fmt::{Display, Debug};
use std::clone::Clone;

pub trait Summary {
    fn summarize_author(&self) -> String;

    fn summarize(&self) -> String {
        format!("(Read more from {}...)", self.summarize_author())
    }
}

#[derive(Debug)]
pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize_author(&self) -> String {
        format!("@{}", self.author)    
    }

    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

#[derive(Debug)]
pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize_author(&self) -> String {
        format!("@{}", self.username)    
    }
    
    // the default implementation is already included not sure if this is how rust works though
    //fn summarize(&self) -> String {
    //    format!("(Read more from {}...)", self.summarize_author())
    //}
}

// pub fn notify(item: &impl Summary) {
//     println!("Breaking news! {}", item.summarize())
// }

// pub fn notify<T: Summary>(item: &T) {
//     println!("Breaking news! {}", item.summarize())
// }

// pub fn notify(item: &(impl Summary + std::fmt::Display)) {
//     println!("Breaking news! {}", item.summarize())
// }

// pub fn notify<T: Summary>(item: &T, other: &T) {
//     println!("Breaking news! {}", item.summarize())
// }

pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize())
}

fn some_function<T, U>(t: &T, u: &U) -> u32 
where
    T: Display + Clone,
    U: Clone + Debug
{
    0
}

struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }    
}

impl<T> Pair<T> 
where T: Display + PartialOrd
{
   fn cmp_display(&self) {
       if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
       } else {
            println!("The largest member is y = {}", self.y);
       }
   }
}

fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("badhat"),
        content: String::from(
            "Rust is the best language ever!",
        ),
        reply: false,
        retweet: false,
    }
}

fn main() {

   
    let tweet = Tweet {
        username: String::from("horse_ebooks"),
        content: String::from(
            "of course, as you probably already know, people",
        ),
        reply: false,
        retweet: false,
    };
    
    let article = NewsArticle {
        headline: String::from("Penguins win the Stanley Cup Championship!"),
        location: String::from("Pittsburgh, PA, USA"),
        author: String::from("Iceburgh"),
        content: String::from(
            "The Pittsburgh Penguins once again are the best \
             hockey team in the NHL.",
        ),
    };
    
    println!("1 new tweet: {}", tweet.summarize());
    println!("New article available! {}", article.summarize());
    
    notify(&tweet);
    notify(&returns_summarizable());
}

