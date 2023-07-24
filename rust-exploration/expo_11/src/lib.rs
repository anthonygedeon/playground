// TODO: figure out how to get compile-time checks for state machine
// Might have to use macros but first figure out your api and how you can use it effectively for games

struct StateMachine;

enum State {
    Unlocked = 0,
    Locked = 1,
}

enum Transition {
    PushCoin = 0,
    PushEmpty = 1,
}

impl StateMachine {
    pub fn new(state: State) {}

    pub fn to<T, F>(&self, func: F) {}
}

#[test]
fn test() {
    let sm: () = StateMachine::new(State::Locked);

    assert_eq!(true, true);
}
