class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_idx;

        for (int i = 0; i < nums.size(); i++)
        {

            auto it = num_idx.find(target-nums[i]);
            if (it != num_idx.end())
            {
                return {it->second, i};
            }
            
            num_idx.insert({nums[i], i});
        }
    }
};
