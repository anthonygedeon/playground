fn main() {
    #[derive(Debug)]
    enum SpreadsheetCell {
        Int(i32), 
        Float(f64), 
        Text(String)
    }

    let mut row = vec![
        SpreadsheetCell::Int(3), 
        SpreadsheetCell::Text(String::from("blue")), 
        SpreadsheetCell::Float(10.12), 
    ];
    
    println!("{:?}", row);

    for i in &mut row {
       match i {
            SpreadsheetCell::Int(_) => *i = SpreadsheetCell::Int(10), 
            SpreadsheetCell::Float(f) => println!("{}", f), 
            SpreadsheetCell::Text(t) => println!("{}", t), 
       }
    }

    println!("{:?}", row); // turns out I can change the enum value
    
}
