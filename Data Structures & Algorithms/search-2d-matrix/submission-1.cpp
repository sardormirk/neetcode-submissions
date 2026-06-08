class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m * n - 1; // r = m
        /*
        target = 3
        1  3  5  7
        10 11 16 20
        23 30 34 60

        l = 0, r = 11, mid = 5, row = 1, col = 1
        int l = 0, r = 4, mid = 2, row = 0, col = 
        */
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid - (n * row);
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target)
            {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return false;
    }
};
