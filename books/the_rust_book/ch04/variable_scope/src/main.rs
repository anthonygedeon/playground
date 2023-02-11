fn main() {

    { // s declaration does not exist yet
        let s = "hello"; // s can be used
    } // s is no longer valid and can't be used
    
    #[cfg(error)] {
        println!("{s}");
    }
}
