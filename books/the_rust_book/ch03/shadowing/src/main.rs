fn main() {
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
        // drop(x)
    }

    println!("The value of x is: {x}");
    
    let y = 1;
    if true {
        let y = y * 100;
        println!("the value of y = {y}");
            
    }
    
    // allowed to change the type since you're creating a new variable
    let spaces = "     ";
    let spaces = spaces.len(); // over shadows the top declaraction

    println!("spaces total is: {spaces}");

    #[cfg(error)] {
        // does not compile since you're changing the type of spaces from &str to usize
        let mut spaces = "      ";
        spaces = spaces.len();
    }
}
