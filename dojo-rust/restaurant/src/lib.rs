//mod back_of_house {
//    pub struct Breakfast {
//        pub toast: String, 
//        seasonal_fruit: String, 
//    }
//
//    impl Breakfast {
//        pub fn summer(toast: &str) -> Breakfast {
//            Breakfast {
//                toast: String::from(toast),
//                seasonal_fruit: String::from("peaches"),
//            }
//        }
//    }
//}
//
//pub fn eat_at_resturant() {
//    let mut meal = back_of_house::Breakfast::summer("Rye");
//    meal.toast = String::from("Wheat");
//    println!("I'd like {} toast please", meal.toast);
//    meal.seasonal_fruit = String::from("blueberries");
//}

mod back_of_house {
    pub enum Appetizer {
        Soup, 
        Salad, 
    }
}

pub fn eat_at_resturant() {
    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;
}
