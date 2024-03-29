use anyhow::Error;

/// While using `&[&str]` to handle flags is convenient for exercise purposes,
/// and resembles the output of [`std::env::args`], in real-world projects it is
/// both more convenient and more idiomatic to contain runtime configuration in
/// a dedicated struct. Therefore, we suggest that you do so in this exercise.
///
/// In the real world, it's common to use crates such as [`clap`] or
/// [`structopt`] to handle argument parsing, and of course doing so is
/// permitted in this exercise as well, though it may be somewhat overkill.
///
/// [`clap`]: https://crates.io/crates/clap
/// [`std::env::args`]: https://doc.rust-lang.org/std/env/fn.args.html
/// [`structopt`]: https://crates.io/crates/structopt
#[derive(Debug)]
pub struct Flags;

impl Flags {
    pub fn new(flags: &[&str]) -> Self {
        for &flag in flags {
            match flag {
                "-n" => unimplemented!(),
                "-l" => unimplemented!(),
                "-i" => unimplemented!(),
                "-v" => unimplemented!(),
                "-x" => unimplemented!(),
                _ => unimplemented!(),
            }
        }
        unimplemented!()
    }
}

pub fn grep(pattern: &str, flags: &Flags, files: &[&str]) -> Result<Vec<String>, Error> {}
