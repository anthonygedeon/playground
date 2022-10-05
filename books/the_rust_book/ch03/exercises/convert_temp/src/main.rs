#[inline]
fn c_to_f(temperature: i32) -> i32 {
    (temperature * 9/5) + 32 
}

#[inline]
fn f_to_c(temperature: i32) -> i32 {
    (temperature - 32) * 5/9
}

fn main() {}

#[cfg(test)]
mod tests {
   
    use super::*;

    #[test]
    fn test_f_to_c() {
        assert_eq!(37, f_to_c(100));
    }

    fn test_c_to_f() {
        assert_eq!(100, c_to_f(37));
    }

}
