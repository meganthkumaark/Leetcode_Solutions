class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();

                int result = performOperation(operand1, operand2, token);
                operands.push(result);
            } else {
                int operand;
                stringstream(token) >> operand;
                operands.push(operand);
            }
        }

        return operands.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const string& op) {
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else {
            // Assume the expression is always valid
            return operand1 / operand2;
        }
    }
};