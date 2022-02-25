#![allow(dead_code)]
#![allow(unused_variables)]

use std::io::{stdout, Write};

use crossterm::{
    ExecutableCommand, execute, Result, queue, 
    cursor::{DisableBlinking, EnableBlinking, MoveTo, RestorePosition, SavePosition, position, Hide, Show}, 
    terminal::{Clear, ClearType, EnterAlternateScreen, size, LeaveAlternateScreen}, 
    style::{self, Stylize, Color, SetBackgroundColor}, 
};

pub struct CursorPosition {
    pub x: u16, 
    pub y: u16

}

fn main() -> Result<()> {
    
    let mut cp = CursorPosition { x: 1, y: 1};

    let mut w = stdout();

    let (row, col) = size().unwrap();
        execute!(
        w, 
        EnterAlternateScreen, 
        EnableBlinking, 
    );
    

    loop {
        cp.x.saturating_add(1);
        cp.y.saturating_add(1);
        let cursor_pos = format!("{}:{}", cp.x, cp.y);
        let status_line = format!("{}{}{}",
                                  " No File ".bold().on(Color::Rgb {r: 47, g: 47, b: 66}), 
                                  " ".repeat((row-15).into()).to_string().on(Color::Rgb {r: 47, g: 47, b: 66}), 
                                  cursor_pos.bold().on(Color::Rgb {r: 20, g: 22, b: 22}));
        execute!(
            w, 
            //Clear(ClearType::All), 
            SetBackgroundColor(Color::Rgb {r: 32, g: 33, b: 49}), 
            style::Print(&status_line), 
            MoveTo(1, 1), 
            style::Print(format!("{} {}", cp.x, cp.y)), 
            )?;

        println!("{} {}", cp.x, cp.y);
        // w.flush()?
    }
   execute!(
        w,
        style::ResetColor,
        Show,
        LeaveAlternateScreen
    )?;

    Ok(())
}
