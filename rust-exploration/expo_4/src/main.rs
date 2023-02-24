use std::ops::Deref;
use std::any::TypeId;

fn hello(s: &str) {
    println!("Hello, {s}");
}

#[derive(Debug)]
struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> Self {
        MyBox(x)
    }
}

impl<T: std::fmt::Debug> Deref for MyBox<T> {
    type Target = T;
    
    fn deref(&self) -> &T {
        //println!("{:?} {:p}", self, &self.0);
        &self.0
    }
}

fn main() {
    let x = 5;
    let y = MyBox::new(x);
    let word = MyBox::new(String::from("Roxy")); 
        
    dbg!(y.deref());
    
    print_type_of(& ((*word)[..]) );
    
    hello("Rust");
    hello(&"Anthony".to_string());
    hello(&word); // calls deref on MyBox -> calls deref on String -> &String turns into &str and the types match! 
    hello(&(*word)); // &String::from("Roxy");
    hello(& ((*word)[..]) ); 
    
    assert_eq!(5, x);
    assert_eq!(5, *(y.deref()));
}

fn print_type_of<T: ?Sized>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}
