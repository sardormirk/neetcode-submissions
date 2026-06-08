class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        /*
        // 
        area for specific index = min(max_left, max_right) - height[i]
        height[l] vs height[r]
        keep track of max_left and max_right

        */
        while (l <= r)
        {
            if (maxLeft <= maxRight) // we know that there is a wall that is greater than or equal to the left wall
            {
                maxLeft = max(maxLeft, height[l]);
                water += maxLeft - height[l];
                l++;
            }
            else
            {
                maxRight = max(maxRight, height[r]);
                water += maxRight - height[r];
                r--;
            }
        }

        return water;
    }
};
