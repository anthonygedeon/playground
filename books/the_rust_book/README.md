# Questions

## 15.5 Interior Mutability
Question 1: What is getting called when we invoke `borrow_mut()`? `RefCell` implements the `BorrowMut` trait as a Blanket implementation but `borrow_mut` is also a method for `RefCell`?

Answer 1: It is calling it's methods but it returns Smart Pointers i.e `Ref` and `RefMut` and one thing about Smart Pointers is that it implements the `Deref` trait

```rust
impl Messenger for MockMessenger {
        fn send(&self, msg: &str) {
            self.sent_messeges.borrow_mut().push(String::from(msg));
        }
    }
```

Question 2: Why doesn't this fail as well?

Answer 2:

```rust 
fn send(&self, msg: &str) {
	// this doesn't panic
	self.sent_messages.borrow_mut().push(String::from(msg));
	self.sent_messages.borrow_mut().push(String::from(msg));
}

```

```rust
// this panics
fn send(&self, msg: &str) {
	 let mut one_borrow = self.sent_messages.borrow_mut();
	 let mut two_borrow = self.sent_messages.borrow_mut();

	 one_borrow.push(String::from(msg));
	 two_borrow.push(String::from(msg));
 }
```

Question 3: Why was this code the right choice for the prompt "Which of the following snippets would violate memory safety using this API?"

```rust
let v1 = v.borrow_mut();
let n = &v1[0];
v.borrow_mut().push(0);
println!("{n}");
```
