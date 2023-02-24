
Q: In this snippet of code, what happens exactly when I add a reference to each slice in the arms?
```rust
impl FromStr for Person {
    type Err = ParsePersonError;
    fn from_str(s: &str) -> Result<Person, Self::Err> {
        let data = s.split(',').collect::<Vec<&str>>();

        match data[..] {
            [name, age]  => {
                if name.is_empty() {
                    return Err(Self::Err::NoName);
                }
                match data.last().unwrap().parse::<usize>() {
                    Ok(age) => Ok(Self { name: name.to_string(), age }),
                    Err(err) => Err(Self::Err::ParseInt(err))
                }
            },
            [name] if name.is_empty() => Err(Self::Err::Empty),
            [_] | [.., _, _] | [_, _, ..] => Err(Self::Err::BadLen),
            [] => Err(Self::Err::Empty),
        }
    }
}
```
A: 
