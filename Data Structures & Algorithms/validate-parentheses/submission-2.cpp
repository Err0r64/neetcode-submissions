class Solution {
public:

    bool match(char open, char closed) {
        if (open == '(') {
            return closed == ')';
        } else if (open == '[') {
            return closed == ']';
        } else if (open == '{') {
            return closed == '}';
        } 

        return false;
    }

    bool isOpen(char c) {
        return c == '[' || c == '(' || c == '{';
    }

    bool isValid(string s) {
        // Track previous and if it matches with a close then pop twice
        // Put half into a stack then compare with the other half
        if (s.size() < 2 || s.size() % 2 != 0) return false;

        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            char cur = s[i];
            if (isOpen(cur)) {
                stack.push(cur);
            } else {
                if (!stack.empty() && match(stack.top(), cur)) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};
