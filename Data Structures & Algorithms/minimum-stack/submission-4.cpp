class MinStack {
public:

    int curMin;
    stack<int> stackVec;
    stack<int> minStack; // Stores prev min and current min at a time

    MinStack() {
        curMin = numeric_limits<int>::max();
    }
    
    void push(int val) {
        // check min
        if (val <= curMin) {
            minStack.push(curMin); // Save previous mins
            curMin = val;
        }
        stackVec.push(val);

    }
    
    void pop() {
        if (stackVec.empty()) return;

        if (stackVec.top() == curMin) {
            curMin = minStack.top();
            minStack.pop();
        }
        stackVec.pop();
    }
    
    int top() {
        if (!stackVec.empty()) {
            return stackVec.top();
        }
        return -1;
    }
    
    int getMin() {
        return curMin;
    }
};
