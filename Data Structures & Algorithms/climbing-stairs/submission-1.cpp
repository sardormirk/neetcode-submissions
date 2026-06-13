class Solution {
public:


    int climbStairs(int n) {

        vector<int> dp(n+1);
        /*
        dp[x] = # of ways to reach the top of a staircase with x steps
        dp[n] = dp[n-1] + dp[n-2]
        dp[0] = 0
        dp[1] = 1
        */

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
