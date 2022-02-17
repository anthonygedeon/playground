
pub mod text_interface {
    use std::collections::HashMap;

    pub struct EmployeeInterface {
        departments: HashMap<String, Vec<String>>
    }

    impl EmployeeInterface {
        
        pub fn new() -> Self {
            Self {
                departments: HashMap::new()
            }
        }

        pub fn add(&mut self, name: &str, department: &str) {
            let department = department.to_lowercase();
            let name = name.to_lowercase();
            let employees = self.departments.entry(department).or_insert(Vec::new());
            employees.push(name);
        }

        pub fn departments(&self) -> HashMap<String, Vec<String>> {
            self.departments.clone() 
        }

    }
}

pub mod average {
    use std::collections::HashMap;

    pub fn get_median(mut list: Vec<i32>) -> i32 {
        if list.len() == 0 {return 0;}
        let middle_pos = (list.len() - 1) / 2;
        list.sort_by(|a, b| a.cmp(b));
        if list.len() % 2 == 0 {
            return (list[middle_pos] + list[middle_pos + 1]) / 2
        } 
        list[middle_pos]
    }

    pub fn get_mode(list: Vec<i32>) -> i32 {
        let mut map = HashMap::new();
        let mut numbers: Vec<(i32, i32)> = vec![];
        for i in list {
            let count = map.entry(i).or_insert(0);
            *count += 1;
        }
        
        for (k, v) in map {
            numbers.push((k, v));
        }
        numbers.sort_by(|a, b| b.1.cmp(&a.1));
        numbers[0].0
    }
}

pub mod pig_latin {
    pub fn translate(word: &str) -> String {
        let vowels = ['a', 'e', 'i', 'o', 'u'];
        let mut result = String::from(word.to_string());
        for c in word.chars() {
            if !vowels.contains(&c) {
                let first_char = result.remove(0);
                result.push(first_char);
            } else {
                break
            }
        }

        result.push_str("ay");
        result.to_string()
    }
}

mod tests_employee_department {
    use super::text_interface::*;
    use std::collections::HashMap;

    #[test]
    fn test_add_employee() {
        let mut roster = EmployeeInterface::new();

        roster.add("Jane", "Sales");
        roster.add("Mark", "Sales");
        roster.add("Bob", "Sales");
        roster.add("Zack", "UI");
        roster.add("Anthony", "Programmer");

        println!("{:?}", roster.departments());

    }
}

mod tests_average {
    use super::average::*;
    
    #[test]
    fn test_empty_list_median() {
        let mut vec: Vec<i32> = vec![]; 
        assert_eq!(get_median(vec), 0);
    }
    
    #[test]
    fn test_two_numbers_median() {
        let mut vec: Vec<i32> = vec![1, 2]; 
        assert_eq!(get_median(vec), 1);
    }

    #[test]
    fn test_even_median() {
        let mut vec = vec![3, 5, 7, 12, 13, 14, 21, 23, 23, 23, 23, 29, 40, 56];
        assert_eq!(get_median(vec), 22);
    }

    #[test]
    fn test_odd_length_median() {
        let mut vec = vec![10, 11, 13, 15, 16, 23, 26];
        assert_eq!(get_median(vec), 15);
    }
    
    #[test]
    fn test_value_frequency_mode() {
        let mut vec = vec![10, 11, 13, 15, 15];
        assert_eq!(get_mode(vec), 15);
    }
    
    #[test]
    #[ignore]
    fn test_no_frequency_mode() {
        let mut vec = vec![10, 11, 13, 15];
        assert_eq!(get_mode(vec), 10);
    }

}

#[cfg(test)]
mod tests_pig_latin {
    use super::pig_latin::translate;

    #[test]
    fn test_word_beginning_with_a() {
        assert_eq!(translate("apple"), "appleay");
    }

    #[test]
    fn test_word_beginning_with_e() {
        assert_eq!(translate("ear"), "earay");
    }

    #[test]
    fn test_word_beginning_with_i() {
        assert_eq!(translate("igloo"), "iglooay");
    }

    #[test]
    fn test_word_beginning_with_o() {
        assert_eq!(translate("object"), "objectay");
    }

    #[test]
    fn test_word_beginning_with_u() {
        assert_eq!(translate("under"), "underay");
    }

    #[test]
    fn test_word_beginning_with_a_vowel_and_followed_by_a_qu() {
        assert_eq!(translate("equal"), "equalay");
    }

    #[test]
    fn test_word_beginning_with_p() {
        assert_eq!(translate("pig"), "igpay");
    }

    #[test]
    fn test_word_beginning_with_k() {
        assert_eq!(translate("koala"), "oalakay");
    }

    #[test]
    fn test_word_beginning_with_y() {
        assert_eq!(translate("yellow"), "ellowyay");
    }

    #[test]
    fn test_word_beginning_with_x() {
        assert_eq!(translate("xenon"), "enonxay");
    }

    #[test]
    fn test_word_beginning_with_q_without_a_following_u() {
        assert_eq!(translate("qat"), "atqay");
    }
    
    #[test]
    fn test_word_beginning_with_ch() {
        assert_eq!(translate("chair"), "airchay");
    }

    #[test]
    fn test_word_beginning_with_th() {
        assert_eq!(translate("therapy"), "erapythay");
    }
    
    #[test]
    fn test_word_beginning_with_thr() {
        assert_eq!(translate("thrush"), "ushthray");
    }

    #[test]
    fn test_word_beginning_with_sch() {
        assert_eq!(translate("school"), "oolschay");
    }
}
