class MinStack {
private:
stack<int> min{};
stack<int> stk{};

public:
    MinStack() = default;
    
    void push(int val) {
        stk.push(val);
        if (min.empty()) {
            min.push(val);
        } else if (min.top() > val) {
            min.push(val);
        } else {
            min.push(min.top());
        }
    }
    
    void pop() {
        stk.pop();
        min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min.top();
    }
};
