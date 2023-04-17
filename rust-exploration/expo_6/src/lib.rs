mod iter {

    pub fn filter<T, F>(list: Vec<T>, func: F) -> Vec<T>
    where
        T: PartialEq,
        F: Fn(&T) -> bool,
    {
        let mut result = vec![];

        for i in list {
            if func(&i) {
                result.push(i);
            }
        }

        result
    }

    pub fn map<T, F, R>(list: Vec<T>, func: F) -> Vec<R>
    where
        F: Fn(T) -> R,
    {
        let mut output = vec![];
        for item in list {
            let el = func(item);
            output.push(el);
        }
        output
    }

    //pub fn fiter_map() -> Option {}
}

#[test]
fn simple() {
    let list = vec![1, 2, 3];
    let list = iter::filter(list, |&x| x != 1);
    assert_eq!(vec![2, 3], list);
}
#[test]
fn test_1() {
    let list = vec![1, 2, 3];
    let list = iter::filter(list, |&x| x == 1);
    assert_eq!(vec![1], list);
}
#[test]
fn test_2() {
    let list = vec!["hello", "bye", "due"];
    let list = iter::filter(list, |&x| x.len() > 3);
    assert_eq!(vec!["hello"], list);
}
