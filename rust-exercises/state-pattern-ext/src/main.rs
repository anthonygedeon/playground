// TODO: Add a reject method that changes the post’s state from PendingReview back to Draft.
// TODO: Require two calls to approve before the state can be changed to Published.
// TODO: Allow users to add text content only when a post is in the Draft state. Hint: have the state object responsible for what might change about the content but not responsible for modifying the Post.

pub struct Post {
    content: String,
}

impl Post {
    pub fn new() -> DraftPost {
        DraftPost {
            content: String::new(),
        }
    }
    
    pub fn content(&self) -> &str {
        &self.content
    }
}

pub struct DraftPost {
    content: String,
}

impl DraftPost {
    pub fn add_text(&mut self, text: &str) {
        self.content.push_str(text);
    }
    
    pub fn request_review(self) -> PendingReviewPost {
        PendingReviewPost {
            content: self.content
        }
    }
}

pub struct PendingReviewPost {
    content: String
}

impl PendingReviewPost {
    pub fn approve(self) -> Post {
        Post {
            content: self.content
        }
    }
}


fn main() {
    let mut post = Post::new();
    
    post.add_text("I ate a salad for lunch today");

    let post = post.request_review();
    
    let post = post.approve();
    assert_eq!("I ate a salad for lunch today", post.content());
}
