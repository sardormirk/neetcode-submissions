class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> max;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            
            max.emplace(nums[i], i);

            if (i >= k - 1)
            {
                while (max.top().second <= i - k)
                {
                    max.pop();
                }

                result.push_back(max.top().first);
            }

           
        }

        return result;

    }
};
