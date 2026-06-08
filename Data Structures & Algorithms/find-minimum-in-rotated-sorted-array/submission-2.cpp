class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
        initial approach:
        rotating is popping the last element, pushing it to the front
        from 1 to n:
            reshift the array (pop front element, append it to the back)
            check if sorted
            perform binary search to find the min

        n log n

        trivial O(n) solution:

        loop through the array, have a minimum variable, update it when you get a new minimum

        O(logn) solution:

        use binary search, but array isn't sorted  (it was however, originally sorted)

        3 4 5 0 1 2 3 

        5 1 2 3 4

        
        int l = 0, r = 6, mid = 3

        nums[l] vs nums[r]:
        if nums[l] < nums[r], array is already sorted, return nums[0]
        else
            look at mid
            if nums[mid] > nums[r]:
                we know we are still in the rotated section
                l = mid + 1
            else
                we know min is mid or to the left of mid




        */

        int l = 0, r = nums.size()-1;

        while (l < r)
        {
            if (nums[l] < nums[r]) return nums[l];
            else
            {
                int m = l + (r - l) / 2;
                if (nums[m] > nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
        }

        return nums[l];
    }
};
