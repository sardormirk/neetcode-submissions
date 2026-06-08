class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = static_cast<int>(heights.size());
        stack<int> max_idx; 

        for (int i = 0; i <= n; i++)
        {
            while (!max_idx.empty() && (i == n || heights[i] <= heights[max_idx.top()]))
            {
                int height = heights[max_idx.top()];
                max_idx.pop();
                int width = max_idx.empty() ? i : i - max_idx.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            max_idx.push(i);
        }
        return maxArea;
    }

};
