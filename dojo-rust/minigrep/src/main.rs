use std::process;
use std::env;

use minigrep::Config;

fn main() {
    let args = env::args().collect::<Vec<String>>();
    
    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        process::exit(1);
    });
    
    if let Err(e) = minigrep::run(config) {
        println!("Application error: {}", e);

        process::exit(1);
    }
}

// Q: Why are you able to pass in `&args` into parse_config even though the parameter is `&[String]`?

// Q: What does the number 1 mean in `process::exit(1)`?

// Q: Why would I ever want to use Box?

// Q: why can't I use crate instead of minigrep for importing the run fn? 
