class Solution {
public:

    int evalToken(int a, int b, char operation)
    {
        int res;
        switch (operation) {
            case '+':
                res = (a + b);
                break;
            case '-':
                res = (a - b);
                break;
            case '*':
                res = (a * b);
                break;
            case '/':
                res = (a / b);
                break; 
        }

        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> result;

        for (const auto& token : tokens)
        {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
            {
                result.push(stoi(token));
            }
            else
            {
                int a = result.top(); result.pop();
                int b = result.top(); result.pop();

                result.push(evalToken(b, a, token[0]));
            }
        }

        return result.top();
    }
};
