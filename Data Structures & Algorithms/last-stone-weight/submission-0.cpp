class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights;

        for (const auto& stone : stones)
        {
            weights.emplace(stone);
        }

        while (weights.size() > 1)
        {
            int x = weights.top(); weights.pop();
            int y = weights.top(); weights.pop();

            int new_weight = abs(x-y);

            if (new_weight != 0)
            {
                weights.emplace(new_weight);
            }
        }

        return weights.size() ? weights.top() : 0;
    }
};
