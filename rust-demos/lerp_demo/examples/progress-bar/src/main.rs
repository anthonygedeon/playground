extern crate lerp_demo;

use lerp_demo::lerp;
use macroquad::prelude::*;

fn ease_out_quart(mut percent: f32) -> f32 {
    percent -= 1.0;
    -(percent * percent * percent * percent - 1.0)
}

fn ease_in_circ(percent: f32) -> f32 {
     1.0 - (1.0 - percent * percent).sqrt()
}

fn ease_in_out_sine(percent: f32) -> f32 {
    -(f32::cos(3.14159 * percent) - 1.0) / 2.0
}

#[macroquad::main("Lerp")]
async fn main() {

    let mut loading_bar_0 = Rect::new(0.0, 0.0, 0.0, 5.0);
    let mut loading_bar_1 = Rect::new(0.0, 0.0, 0.0, 5.0);
    let mut loading_bar_2 = Rect::new(0.0, 0.0, 0.0, 5.0);
    let mut loading_bar_3 = Rect::new(0.0, 0.0, 0.0, 5.0);

    loop {
        clear_background(BLACK);

        draw_text(format!("{}", get_fps()).as_str(), 20.0, 20.0, 30.0, WHITE);
        
        draw_rectangle(loading_bar_0.x, (screen_height() / 2.0) - loading_bar_0.h-20.0, loading_bar_0.w, loading_bar_0.h, WHITE);
        draw_rectangle(loading_bar_1.x, (screen_height() / 2.0) - loading_bar_1.h, loading_bar_1.w, loading_bar_1.h, WHITE);
        draw_rectangle(loading_bar_2.x, (screen_height() / 2.0) - loading_bar_2.h + 20.0, loading_bar_2.w, loading_bar_2.h, WHITE);
        draw_rectangle(loading_bar_3.x, (screen_height() / 2.0) - loading_bar_3.h + 40.0, loading_bar_3.w, loading_bar_3.h, WHITE);
        
        loading_bar_0.w = lerp(loading_bar_1.w, screen_width(), dt);
        loading_bar_1.w = lerp(loading_bar_1.w, screen_width(), ease_out_quart(dt));
        loading_bar_2.w = lerp(loading_bar_2.w, screen_width(), ease_in_circ(dt));
        loading_bar_3.w = lerp(loading_bar_2.w, screen_width(), ease_in_out_sine(dt));

        next_frame().await
    }
}
