//#[derive(Debug)]
struct Rectangle {
    width: u32, 
    height: u32,
}

impl Rectangle {
    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size
        }
    }

    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn width(&self) -> bool {
        self.width > 0
    }
    
    fn can_hold(&self, rect: &Rectangle) -> bool {
        self.width > rect.width && self.height > rect.height
    }
}

fn main() {
    let sq1 = Rectangle::square(30);
    let sq2 = Rectangle::square(10);
    let sq3 = Rectangle::square(15);

    println!("Can rect1 hold rect2? {}", sq1.can_hold(&sq2));
    println!("Can rect1 hold rect3? {}", sq1.can_hold(&sq3));
}
