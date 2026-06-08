class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> top;

        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for (const auto& [key, value] : freq)
        {
            top.push(make_pair(value, key));
        }
        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            result.push_back(top.top().second);
            top.pop();
        }

        return result;
    }
};
