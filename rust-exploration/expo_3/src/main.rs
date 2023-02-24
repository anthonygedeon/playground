#![allow(unused)]

enum List {
    Cons(i32, Box<List>),
    Nil,
}

fn main() {
    use List::{Cons, Nil};
    println!("{}", std::mem::size_of::<Box<str>>());
    //println!("{}", std::mem::size_of::<List>());
    println!("{}", std::mem::size_of::<&()>());
    println!("{}", std::mem::size_of::<usize>());
    println!("{}", std::mem::size_of::<i32>());
    println!("{}", std::mem::size_of::<Box<i32>>());
    println!("{}", std::mem::size_of::<Box<()>>());

    //let list = Cons(0, Cons(1, Cons(2, Cons(3, Cons(4, Nil)))));
    
    let a = String::from("Deref");
    let b = &a;
    let c = &b;
    let d = &c;
    let e = &d;
    let result = Box::new(&e);
    

    println!("{}", result);
}

fn func<T: ?Sized>(t: Box<T>) {} 
