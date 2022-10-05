fn nth_fib(n: u32) -> u32 {
    let mut fib: Vec<u32> = vec![1, 1];
    for i in 0..(n as usize - 2) {
        let result = fib[i] + fib[i+1];
        fib.push(result);
    }
    fib.last().unwrap().to_owned()

}

fn main() {
    nth_fib(7);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_nth_7() {
        assert_eq!(13, nth_fib(7));
    }

    #[test]
    fn test_nth_10() {
        assert_eq!(55, nth_fib(10));
    }
}
