class Solution {
public:
    vector<int> countBits(int n) {
        /*
        n = 4;
        i
        0 0000 num_bits[0] = 0
        1 0001 1 + num_bits[0] num_bits[i-1]
        2 0010 1 + num_bits[0] num_bits[i-2]
        3 0011 1 + num_bits[1] num_bits[i-2]
        4 0100 num_bits[4] = 1 + num_bits[0]
        5 0101 num_bits[5] = 1 + num_bits[1] (num_bits[i - 4])
        6 0110
        7 0111
        8 1000 num_bits[8] = 1 + num_bits[0] (num_bits[i-8])
        9 1001
        10 1010 num_bits[10] = 1 + num_bits[2]

        */

        vector<int> dp(n+1);
        int offset = 1;

        for(int i = 1; i <= n; i++)
        {
            if (offset * 2 == i)
                offset = i;

            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
};
