class Solution {
public:
    bool isValid(string s) {

        /*
        ([{}])

        if opening type of bracket, insert into stack
        otherwise check stack.top() to see if its a matching pair, if it isnt return false



        */

        unordered_map<char, char> brackets{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> last_bracket;

        for (const auto& c : s)
        {
            if (brackets.contains(c))
            {
                if (!last_bracket.empty())
                {
                    char last = last_bracket.top();
                    if (brackets[c] == last)
                    {
                        last_bracket.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                last_bracket.push(c);
            }
        }

        if (!last_bracket.empty()) return false;

        return true;
    }
};
