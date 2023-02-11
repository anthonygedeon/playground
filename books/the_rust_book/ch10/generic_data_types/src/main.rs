fn largest_i32(list: &[i32]) -> &i32 {
    let mut largest = &list[0];
    
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    
    largest
}

fn largest_char(list: &[char]) -> &char {
    let mut largest = &list[0];
    
    for item in list {
        if item > largest {
        }
    }
    
    largest
}

use std::cmp::{PartialOrd, PartialEq};
use std::ops::Add;

fn largest<T: PartialOrd + PartialEq>(list: &[T]) -> &T {
    let mut largest = &list[0];
    
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    
    largest
}

struct Point<T> {
    x: T,
    y: T,
}

impl<T: Add> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

struct PointM<X1, Y1> {
    x: X1,
    y: Y1
}

impl<X1, Y1> PointM<X1, Y1> {
    fn mixup<X2, Y2>(self, other: PointM<X2, Y2>) -> PointM<X1, Y2> {
        PointM {
            x: self.x,
            y: other.y
        }
    }
}

fn main() {
    let integer = Point { x: 5, y: 10 };
    let float = Point { x: 1.0, y: 4.0 };
    let p = Point { x: 5, y: 10 };
    //let wont_work = Point { x: 4, y: 4.0 }; 
    
    let p1 = PointM { x: 5, y: 10.4 };
    let p2 = PointM { x: "Hello", y: 'c' };

    let p3 = p2.mixup(p1);

    println!("p3.x = {}, p3.y = {}", p3.x, p3.y);
    
    println!("{}", float.distance_from_origin());
    println!("p.x = {}", p.x());
    
    let number_list = vec![34, 50, 25, 100, 65];

    let result = largest_i32(&number_list);
    println!("The largest number is {}", result);

    
    let char_list = vec!['a', 'A', 'B', 'u', 'O', 'X', 'E'];
    
    let result = largest_char(&char_list);
    println!("The largest char is {}", result);
    
    let number_list = vec![34, 50, 25, 100, 65];
    
    println!("=====================Generic=====================");
    
    let result = largest(&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['a', 'A', 'B', 'u', 'O', 'X', 'E'];
    
    let result = largest(&char_list);
    println!("The largest char is {}", result);
}