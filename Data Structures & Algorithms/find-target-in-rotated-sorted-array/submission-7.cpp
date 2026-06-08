class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        looking for 3

        // 3 4 5 1 2  

        l = 0, r = 4, mid = 2

        if (nums[m] == target) return m;

        if (nums[m] < nums[r] && target > nums[m]) l = m + 1
            perform normal binary search
        else if (prev case && target < nums[m]) -> target is before m r = m-1
        
        else if (nums[m] > nums[r], target > nums[m]) l = m+1
        else r = mid <- reached deflection point
            perform normal binary search


        deflection point = index before first index of  next sorted array

        [3, 4, 5, 1, 2]
        
        l = 0, r = 4, m = 2

        l = 2, r = 4, m = 3
        l = 2, r = 3, m = 2
        l = 2, r = 3, m = 2
        l = 2, r = 3, m = 2

        */

        int l = 0, r = nums.size()-1;
        
        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[r])
                l = m + 1;
            else {
                r = m;
            }
        }
        
        int pivot = l;
        l = 0;
        r = nums.size() - 1;
        if (target > nums[r])
        {
            r = pivot-1;
        }
        else if (target >= nums[pivot])
        {
            l = pivot;
        }

        auto it = lower_bound(nums.begin() + l, nums.begin() + r, target);
        if (it != nums.end() && *it == target)
            return it - nums.begin();

        return -1;

    }
};
