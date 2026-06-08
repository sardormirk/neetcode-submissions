class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        /* 

            28 > 6
            40 -> 5


        */

        int n = temperatures.size();

        vector<int> result(n);
        stack<int> temp_indices;

        for (int i = 0; i < n; i++)
        {
            while (!temp_indices.empty() && temperatures[temp_indices.top()] < temperatures[i])
            {
                int idx = temp_indices.top();
                result[idx] = i - idx;
                temp_indices.pop();
            }

            temp_indices.push(i);
        }

        return result;
    }
};
