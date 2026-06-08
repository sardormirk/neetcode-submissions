class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int max_water = INT_MIN; 
        /*
        water level gated by smaller bar
        if (l < r)
            l++
        else
            r--

        max =  max(max, (l < r) ? l * (l-r) : r * (l - r))
        */

        while (l < r)
        {

            int bar1 = heights[l], bar2 = heights[r];
            int water = (bar1 < bar2) ? bar1 * (r-l) : bar2 * (r-l);

            cout << l << " " << r << " " << " " << bar1 << " " << bar2 << " " << water << endl; 
            max_water = max(max_water, water);

            if (bar1 < bar2)
            {
                l++;
            }
            else if (bar1 > bar2)
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }

        return max_water;

    }
};
