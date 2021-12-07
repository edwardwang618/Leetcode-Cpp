/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<int> stk, stk1;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (stk1.empty() || x <= stk1.top()) stk1.push(x);
    }
    
    void pop() {
        if (stk.top() == stk1.top()) stk1.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

