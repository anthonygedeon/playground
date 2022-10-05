fn main() {
    #[cfg(error)] {
        // x variable is immutable by default. We do not need to specify a immutable keyword
        let x = 5;
        println!("The value of x is: {x}");
        x = 6;
        println!("The value of x is: {x}");
    }

    // y variable is now mutable 
    let mut y = 10;
    println!("The value of y is: {y}");
    y = 6;
    println!("The value of y is: {y}");

    let (mut x, y) = (1, 0);

    x = 10;
    println!("The value of x is: {x}");

    println!("The value of y is: {y}");

}
