use macroquad::prelude::*;
use macroquad::experimental::animation::Animation;

#[macroquad::main("Sprite Animation Experiment")]
async fn main() {
    
    let frames = vec![
        load_texture("assets/tile000.png").await.unwrap(),
        load_texture("assets/tile001.png").await.unwrap(),
        load_texture("assets/tile002.png").await.unwrap(),
        load_texture("assets/tile003.png").await.unwrap(),
        load_texture("assets/tile004.png").await.unwrap(),
        load_texture("assets/tile005.png").await.unwrap(),
        load_texture("assets/tile006.png").await.unwrap(),
        load_texture("assets/tile007.png").await.unwrap(),
        load_texture("assets/tile008.png").await.unwrap(),
        load_texture("assets/tile009.png").await.unwrap(),
        load_texture("assets/tile010.png").await.unwrap()
    ];

    loop {
        clear_background(WHITE);

        for mut i in 0..frames.len() {
            if i == frames.len() {
                i = 0;
            }

            draw_texture(frames[i], 
                         screen_width() / 2.0 - frames[0].width(), 
                         screen_height() / 2.0 - frames[0].height(), 
                         WHITE);
        }


        next_frame().await
    }
}
