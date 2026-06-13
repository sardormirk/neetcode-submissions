class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> k_biggest;

        for (int num : nums)
        {
            k_biggest.emplace(num);
            if (k_biggest.size() > k)
            {
                k_biggest.pop();
            }
        }

        return k_biggest.top();
    }
};
