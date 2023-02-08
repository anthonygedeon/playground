
mod exercise_one {

    use std::collections::HashMap;

    pub fn mean(list: &Vec<usize>) -> Option<usize> {
        if list.is_empty() {
            return None;
        }
        Some(list.into_iter().sum::<usize>() / list.len())
    }

    pub fn median(list: &Vec<usize>) -> Option<usize> {
        if list.is_empty() {
            return None;
        }

        let mut sorted_list = list.clone();
        sorted_list.sort();

        let middle = (((sorted_list.len() / 2) as f32).floor()) as usize;

        Some(sorted_list[middle])
    }

    pub fn mode(list: &Vec<usize>) -> Option<usize> {
        if list.is_empty() {
            return None;
        }

        let mut tally: HashMap<usize, usize> = HashMap::new();

        for n in list {
            *tally.entry(*n).or_insert(0) += 1;
        }
        
        Some(*tally.iter().max_by_key(|e| e.1).unwrap().0)
    }
}

mod exercise_two {
    // See Exercism for my pig latin solution
}

mod exercise_three {
    
    use std::collections::HashMap;

    type Role = String;

    pub struct Employee {
        pub name: String,
        pub role: String
    }
    
    pub struct Department {
        pub map: HashMap<Role, Vec<String>> }

    impl Department {
        pub fn new() -> Self {
            Self {
                map: HashMap::new()
            }
        }

        pub fn add(&mut self, em: Employee) {
            self.map.entry(em.role).or_insert(Vec::<String>::new()).push(em.name);
        }

        pub fn list(&self, key: &str) -> &Vec<String> {
            match self.map.get(key) {
                Some(employees) => employees, 
                None => todo!()
            }
        }

    }

    
}

fn main() {
    use exercise_one::{
        mean,
        median,
        mode
    };

    let v = vec![32, 10, 0, 29, 33, 46, 5, 10];

    println!("{}", mean(&v).unwrap());
    println!("{}", median(&v).unwrap());
    println!("{}", mode(&v).unwrap());

    use exercise_three::{
        Employee,
        Department
    };

    let mut department = Department::new();
    

    let employee_list: Vec<Employee> = vec![
        Employee{
            name: "Sally".to_string(),
            role: "Engineering".to_string()
        },
        Employee{
            name: "Megan".to_string(),
            role: "UX".to_string()
        },
        Employee{
            name: "Bob".to_string(),
            role: "Engineering".to_string()
        },
        Employee{
            name: "John".to_string(),
            role: "Engineering".to_string()
        },
        Employee{
            name: "Amir".to_string(),
            role: "Sales".to_string()
        },

    ];
    
    for employee in employee_list {
        department.add(employee);
    }

    let mut list = department.list("Engineering").clone();
    list.sort();

    println!("{:#?}", list);
}
