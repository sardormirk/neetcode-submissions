class MinStack {
public:

    stack<int> norm;
    stack<int> min; 

    MinStack() {
        
    }
    
    void push(int val) {
        norm.push(val);

        if (min.empty() || val <= min.top())
        {
            min.push(val);
        }
    }
    
    void pop() {
        int num = norm.top();

        if (num == min.top())
        {
            min.pop();
        }

        norm.pop();
    }
    
    int top() {
        return norm.top();
    }
    
    int getMin() {
        return min.top();
    }
};
