const THREE_HOURS_IN_SECONDS: u32 =  60 * 60 * 3;

fn main() {
    const MY_NAME: &str = "Kyle";

    const EXPR: u32 = {
        let x = 10;
        let y = 10;
        y * x
    };

    const WHILE: u8 = {
        let mut sum = 0;

        while sum != 10 {
            sum += 1;
        }

        sum
    };

    const MATCH: Result<bool, bool> = match 1u32 {
        1 => Ok(true),
        _ => Err(false) 
    };

    println!("{}", MY_NAME);
    println!("{}", EXPR);
    println!("{}", THREE_HOURS_IN_SECONDS);
    println!("{:?}", MATCH);
    println!("{:?}", WHILE);
}
