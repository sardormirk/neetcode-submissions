class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /* 
        #hours it takes to finish a pile = ceil(piles[i] / k)

        brute force approach:
        start with maximum k = max(piles)
        decrement max k and loop over the area, checking if k is still valid


        better approach

        upper bound of k is max(piles);

        1 <= k <= max(piles)
        do binary search on this bound,
        if 


        1 <= k <= 10
        
        
        5

        25 10 23 4

        k range
        [1..25]
        mid = 13

        */

        int l = 1, r = *max_element(piles.begin(), piles.end()), k = INT_MAX;
        

        while (l <= r)
        {
            long long time = 0;
            int mid = l + (r - l) / 2;

            for (const auto& pile : piles)
            {
                time += ceil(pile / (double)mid);
            }

            if (time <= h)
            {
                k = min(k, mid);
                r = mid - 1;
            }
            else
            {   
                l = mid + 1;
            }
        }

        return k;
    }
};
