class Solution {
public:
    bool isOperator(string c) {
        return c == "+" ||
               c == "-" ||  
               c == "*" ||
               c == "/";     
    }

    int compute(stack<int> &order, const string _operator) {
        int operand1 = order.top(); order.pop();
        int operand2 = order.top(); order.pop();
    
        if (_operator == "+") {
            return operand2 + operand1;
        } else if (_operator == "-") {
            return operand2 - operand1;
        } else if (_operator == "*") {
            return operand2 * operand1;
        } else {
            return operand2 / operand1;
        }

    }


    int evalRPN(vector<string>& tokens) {
        stack<int> order;

        for (int i = 0; i < tokens.size(); i++) {
            string cur = tokens[i];
            if (isOperator(cur)) {
                int result = compute(order, cur);
                order.push(result);
            } else {
                order.push((int) stoi(cur)); // Using atoi(begin(), end(), result) is faster but lower level (no safeguards)
            }
        }

        return order.top();
    }
};
