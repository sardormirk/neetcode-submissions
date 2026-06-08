class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        For each index i, store leftMost[i] -> index of the first rectangle that is shorter to the left
                                rightMost[i] -> index of first retangle that is shorter to the right 

        Gives us for height[i], the maximum area of the rectangle that can be made out of bars of height[i]
        */
        int n = static_cast<int>(heights.size()), max_area = 0;
        vector<int> leftMost(n, -1), rightMost(n, n);

        stack<int> min_idc;

        int minIdx = 0;

        for (int i = 0; i < n; i++)
        {
            while (!min_idc.empty() && heights[min_idc.top()] >= heights[i])
            {
                min_idc.pop();
            }

            if (!min_idc.empty())
            {
                leftMost[i] = min_idc.top();
            }

            min_idc.push(i);
        }

        while(!min_idc.empty()) min_idc.pop();

        for (int i = n-1; i >= 0; i--)
        {
            while (!min_idc.empty() && heights[min_idc.top()] >= heights[i])
            {
                min_idc.pop();
            }

            if (!min_idc.empty())
            {
                rightMost[i] = min_idc.top();
            }

            min_idc.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            int l = leftMost[i] + 1, r = rightMost[i] - 1;
            max_area = max(max_area, heights[i] * (r - l + 1));
        }

        return max_area;
    }
};
