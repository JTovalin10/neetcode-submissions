class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
        nstk.push(val);
        if (!mstk.empty()) {
            int new_min = std::min(val, mstk.top());
            mstk.push(new_min);
        } else {
            mstk.push(val);
        }
    }
    
    void pop() {
        nstk.pop();
        mstk.pop();
    }
    
    int top() {
        int top = nstk.top();
        return top;
    }
    
    int getMin() {
        int min = mstk.top();
        return min;
    }

private:
stack<int> nstk{};
stack<int> mstk{};
};
