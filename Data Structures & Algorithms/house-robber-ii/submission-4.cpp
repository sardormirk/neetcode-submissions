class Solution {
public:
    int rob(vector<int>& nums) {
        /*

        dp[i] = money made until ith house

        dp[i] = max(dp[i-1], dp[i-2] + nums[i])

        1 2 
        4 3  
          |    |
        1 2 3 4
        |   |


        */

        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        return max(robHouses(vector<int>(nums.begin(), nums.end()-1)), 
        
                   robHouses(vector<int>(nums.begin()+1, nums.end())));

    }

    int robHouses(vector<int> nums)
    {
        int n = nums.size();
    
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};
