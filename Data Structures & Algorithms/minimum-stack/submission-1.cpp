class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
       reg_stk.push(val); 

        // must check if its the new min for the skt
        int c_min = min_stk.empty() ? val : min_stk.top();
        int p_min = min(c_min, val);
        min_stk.push(p_min);
    
    }
    void pop() {
        reg_stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return reg_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
private:
stack<int> reg_stk{};
stack<int> min_stk{};
};
