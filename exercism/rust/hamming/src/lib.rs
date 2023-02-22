/// Return the Hamming distance between the strings,
/// or None if the lengths are mismatched.
pub fn hamming_distance(s1: &str, s2: &str) -> Option<usize> {
    if s1.len() != s2.len() { return None; }
    
    let hamming_distance = s1.chars()
        .zip(s2.chars())
        .fold(0, |mut diff: usize, (nucletide_a, nucletide_b)| {
            if nucletide_a != nucletide_b { diff += 1; } 
            diff
        });

    Some(hamming_distance) 
}
