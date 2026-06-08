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
                if (!last_bracket.empty() && last_bracket.top() == brackets[c])
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
                last_bracket.push(c);
            }
        }

        return last_bracket.empty();
    }
};
