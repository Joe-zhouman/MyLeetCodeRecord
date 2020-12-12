// Administrator
// LeetCode-Cpp
// 0232_MyQueue
// 2020-07-26-20:27
// https://leetcode-cn.com/u/joe_zm/
#pragma once
#include <stack>
class my_queue {
    std::stack<int> init_stack_;
    std::stack<int> reverse_stack_;
public: 
    /** Initialize your data structure here. */
    my_queue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        init_stack_.push(x);
        auto temp_stack = init_stack_;
        reverse_stack_ = {};
        while (!temp_stack.empty()) {
            reverse_stack_.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto t = reverse_stack_.top();
        reverse_stack_.pop();
        auto temp_stack = reverse_stack_;
        init_stack_ = {};
        while (!temp_stack.empty()) {
            init_stack_.push(reverse_stack_.top());
            temp_stack.pop();
        }
        return t;
    }

    /** Get the front element. */
    int peek() {
        return reverse_stack_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return init_stack_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */