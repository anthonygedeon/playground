fn main() {
    let f = |_| (); // sometimes called the "toilet closure"

    let s = String::from("Hello");

    f(s);
}
