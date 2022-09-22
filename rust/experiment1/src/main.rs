macro_rules! min {
  ( $( $a:expr ),+ ) => {{
      let mut temp_vec = Vec::new();
      $(
        temp_vec.push($a);
      )*
      let min = temp_vec.iter().min().unwrap();
      *min
  }};
}

fn main() {
  let sm: i32 = min![1, 2, 3, 4, 0];
  println!("{:?}", sm);
}
