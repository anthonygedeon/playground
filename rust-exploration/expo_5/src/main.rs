enum Color {
    RGB(u8, u8, u8),
    HSV(u8, u8, u8),
}

enum Message {
    ChangeColor(Color)
}

fn main() {
    let msg = Message::ChangeColor(Color::HSV(0, 100, 205));

    match msg {
        Message::ChangeColor(Color::RGB(r, g, b)) => println!(
            "Change the color to red {}, green {}, and blue {}",
            r, g, b
        ),
        Message::ChangeColor(Color::HSV(h, s, v)) => println!(
            "Change the color to hue {}, saturation {}, and value {}",
            h, s, v
        ),
        _ => (),
    }
}
