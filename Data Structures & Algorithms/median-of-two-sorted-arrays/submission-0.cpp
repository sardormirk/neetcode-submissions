class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
              
                  |
        1 2 3 4 8 9 10 11 total = 14, lefthalf = 7, righthalf = 7
                      |
              
        5 6 9 10 11 12 
          
        
        |
        1 2 3 4 5 6 8 9 9 10 10 11 11 12

        median = (8 + 9) / 2
               = 8.5

                    |
        1 2 3 4 5 6 7 8 9 10 11 total = 11, left half = (total + 1) / 2
    
            |       
        1 2 3 4 5 5 6 6 7 7 8 8

        total % 2 -> odd, median = nums[total/2]
        else -> even, median = (nums[total/2] + nums[total/2 - 1]) / 2
        */

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if (A.size() > B.size())
        {
            swap(A, B);
        }

        int l = 0, r = A.size(), total = A.size() + B.size(), half = (total+1) / 2;

        while (l <= r)
        {
            int mid = l + (r - l) / 2; // index where we insert the partition, anything before mid, is left, anything after, is right
            int mid2 = half - mid;

            int aLeft = (mid > 0) ? A[mid-1] : INT_MIN;
            int aRight = (mid < A.size()) ? A[mid] : INT_MAX;
            int bLeft = (mid2 > 0) ? B[mid2-1] : INT_MIN;
            int bRight = (mid2 < B.size()) ? B[mid2] : INT_MAX;

            if (aLeft <= bRight && bLeft <= aRight)
            {
                if (total % 2)
                {
                    return max(aLeft, bLeft);
                }
                else
                {
                    return (max(aLeft, bLeft) + min(aRight, bRight)) / (double)2;
                }
            }
            else if (aLeft > bRight)
            {
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }
    }
};
