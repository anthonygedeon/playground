use std::{iter::FromIterator};

#[derive(Debug )]
struct Node<T> {
    data: T,
    next: Option<Box<Self>>
}

impl<T> Node<T> {
    fn new(data: T) -> Self {
        Self {
            data,
            next: None
        }
    }
}

type Link<T> = Option<Box<Node<T>>>;

#[derive(Debug)]
pub struct SimpleLinkedList<T> {
    head: Link<T>,
    tail: Link<T>,
}

impl<T> SimpleLinkedList<T> {
    pub fn new() -> Self {
        Self {
            head: None,
            tail: None
        }
    }

    // You may be wondering why it's necessary to have is_empty()
    // when it can easily be determined from len().
    // It's good custom to have both because len() can be expensive for some types,
    // whereas is_empty() is almost always cheap.
    // (Also ask yourself whether len() is expensive for SimpleLinkedList)
    pub fn is_empty(&self) -> bool {
        unimplemented!()
    }

    pub fn len(&self) -> usize {
        let mut count: usize = 0;
        
        let mut tmp = &self.head;
        while let Some(node) = tmp {
           tmp = &node.next;
           count += 1;
        } 
        
        count
    }

    pub fn push(&mut self, _element: T) {
        let new_node = Box::new(Node::new(_element));
        
        // grab the last node (before None)
        let mut tmp = &self.head;
        while let Some(node) = tmp {
            tmp = &node.next;
        } 
         
    }

    pub fn pop(&mut self) -> Option<T> {
        unimplemented!()
    }

    pub fn peek(&self) -> Option<&T> {
        unimplemented!()
    }

    #[must_use]
    pub fn rev(self) -> SimpleLinkedList<T> {
        unimplemented!()
    }
}

impl<T> FromIterator<T> for SimpleLinkedList<T> {
    fn from_iter<I: IntoIterator<Item = T>>(_iter: I) -> Self {
        let mut list = SimpleLinkedList::new();
        list
    }
}

// In general, it would be preferable to implement IntoIterator for SimpleLinkedList<T>
// instead of implementing an explicit conversion to a vector. This is because, together,
// FromIterator and IntoIterator enable conversion between arbitrary collections.
// Given that implementation, converting to a vector is trivial:
//
// let vec: Vec<_> = simple_linked_list.into_iter().collect();
//
// The reason this exercise's API includes an explicit conversion to Vec<T> instead
// of IntoIterator is that implementing that interface is fairly complicated, and
// demands more of the student than we expect at this point in the track.

impl<T> From<SimpleLinkedList<T>> for Vec<T> {
    fn from(mut _linked_list: SimpleLinkedList<T>) -> Vec<T> {
        let list_vec: Vec<T> = Vec::new();
        list_vec
    }
}
