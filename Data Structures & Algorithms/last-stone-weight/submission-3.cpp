class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        int maxStone = 0;

        for(const auto& weight : stones)
        {
            maxStone = max(maxStone, weight);
        }

        vector<int> weights(maxStone+1, 0);
        
        for(const auto& weight : stones)
        {
            weights[weight]++;
        }

        int first = maxStone, second = maxStone;

        while (first > 0)
        {
            if (weights[first] % 2 == 0)
            {
                first--;
                continue;
            }

            int nextStone = min(first-1, second);
            while (nextStone > 0 && (weights[nextStone] == 0))
            {
                nextStone--;
            }

            if (nextStone == 0) return first;

            second = nextStone;
            weights[first]--;
            weights[second]--;
            weights[first-second]++;
            first = max(first-second, second);
        }

        return first;
    }
};
