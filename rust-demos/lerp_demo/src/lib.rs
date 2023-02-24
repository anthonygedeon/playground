/// Return a default value if b < x > a
fn clamp(a: f32, b: f32, x: f32) -> f32 {
    f32::max(a, f32::min(x, b))
}

/// Return 0 if input is negative or 1 if input is > 1
fn internal_clamp01(input: f32) -> f32 {
    clamp(0.0, 1.0, input)
}

/// Returns a point between `start` and `end` based on the provided `percentage`.
///
/// Note: `percentage` will clamp based on the scalar values 0 and 1 respectively
///
/// # Examples
///
/// ```
/// use lerp_demo::lerp;
///
/// assert_eq!(lerp(6.0, 36.0, 0.3), 15.0);
/// assert_eq!(lerp(0.0, 25.0, -0.3), 0.0);
/// assert_eq!(lerp(0.0, 25.0, 1.5), 25.0);
/// ```
pub fn lerp(start: f32, end: f32, mut percentage: f32) -> f32 {
    percentage = internal_clamp01(percentage);

    // Calculate the mid-point between start and end
    // Multiply the result with the percentage
    // The result will be added back to start so we can get the point that is in between the line
    start + (end - start) * percentage
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn lerp_regular_use_case_1() {
        assert_eq!(lerp(0.0, 4.0, 0.5), 2.0);
    }

    #[test]
    fn lerp_regular_use_case_2() {
        assert_eq!(lerp(6.0, 12.0, 0.2), 7.2);
    }

    #[test]
    fn lerp_return_end_when_percentage_is_1() {
        assert_eq!(lerp(0.0, 4.0, 1.0), 4.0);
    }

    #[test]
    fn lerp_when_percentage_is_more_than_1() {
        assert_eq!(lerp(0.0, 25.0, 1.5), 25.0);
    }

    #[test]
    fn lerp_percentage_when_negative() {
        assert_eq!(lerp(0.0, 25.0, -0.3), 0.0);
    }
}
