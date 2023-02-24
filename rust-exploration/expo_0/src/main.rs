fn main() {
    let mut a = String::from("hello");
    // using the `move` keyword doesn't apply for the fn* traits
    let func = |s: String|  {
        a.push_str("hello"); 
        format!("{a} {s}");
    };
    
    do_something_v4(func);
}

fn do_something_v4<F>(f: F) 
where
    F: FnOnce(String) -> ()
{
    f(String::from("v4"));
}
