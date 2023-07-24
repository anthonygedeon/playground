#[allow(dead_code)]
#[derive(Copy, Clone)]
struct Fibonacci {
    prev: u32,
    curr: u32,
}

impl Fibonacci {
    fn new() -> Self {
        Self { prev: 1, curr: 1 }
    }
}

impl Iterator for Fibonacci {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        let result = self.prev + self.curr;
        self.prev = self.curr;
        self.curr = result;
        Some(result)
    }
}

fn main() {
    let fib = Fibonacci::new();
    for i in fib.take(10) {
        println!("{:?}", i);
    }

    let seq: Vec<u32> = fib.take(10).collect();
    println!("{:?}", seq);

    let seq: Vec<u32> = fib.take(10).map(|x| x >> 1).collect();
    println!("{:?}", seq);
}
