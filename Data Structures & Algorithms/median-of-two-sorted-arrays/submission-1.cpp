class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*

        1 2 3 4 5

        5 6 

        1 2 3 4 5 5 6  , total = 7, median = 4.5

        A = 0 
        B = 0

        loop i < total / 2 + 1

        A = 3
        B = 4
        */

        int total = nums1.size() + nums2.size();

        int A = 0, B = 0, i = 0, j = 0;

        for (int count = 0; count < total / 2 + 1; count++)
        {
            A = B;
            if (i < nums1.size() && j < nums2.size())
            {
                if (nums1[i] <= nums2[j])
                {
                    B = nums1[i];
                    i++;
                }
                else
                {
                    B = nums2[j];
                    j++;
                }
            }
            else if (i < nums1.size())
            {
                B = nums1[i];
                i++;
            }
            else {
                B = nums2[j];
                j++;
            }
        }

        if (total % 2)
        {
            return B;
        }
        else
        {
            return (A + B) / 2.0;
        }
    }
};
