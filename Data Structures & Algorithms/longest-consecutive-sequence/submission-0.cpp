class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        int max_count = count;
        unordered_set<int> seq;

        for(int i = 0; i < nums.size(); i++)
        {
            seq.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = seq.find(nums[i] - 1);
            count = 0;

            if (it == seq.end())
            {  
                int seq_start = nums[i];
                while (seq.find(seq_start) != seq.end())
                {
                    count++;
                    seq_start++;
                }
            }
            max_count = max(max_count, count);
        }

        return max_count;
    }
};
