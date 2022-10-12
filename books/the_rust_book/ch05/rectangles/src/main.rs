#[derive(Debug)]
struct Rectangle {
    width: u32, 
    height: u32,
}

fn main() {
    let scale = 2;
    let rect1 = Rectangle {
        width: dbg!(30 + 10 / 20 * 3 * scale), 
        height: 50, 
    };
   
    dbg!(&rect1);

}
