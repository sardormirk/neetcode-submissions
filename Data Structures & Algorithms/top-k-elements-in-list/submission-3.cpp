class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> freq;
        

        for (const auto& num : nums) {
            freq[num]++;
        }

        for (const auto& [key, value] : freq)
        {
            buckets[value].push_back(key);
        }

        vector<int> results;
        for (int i = buckets.size()-1; i >= 0; i--) 
        {
            for (const auto& x : buckets[i])
            {
                results.push_back(x);
            }

            if (results.size() == k) return results;
        }


    }
};
