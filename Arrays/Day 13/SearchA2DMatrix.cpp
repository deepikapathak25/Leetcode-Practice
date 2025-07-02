class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        /* 🔍 Brute Force Approach
           - Time Complexity: O(n * m)
           - Space Complexity: O(1)
           - Simply iterate through all elements
        */
        /*
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
        */

        /* ⚡ Optimized Approach (Binary Search)
           - Time Complexity: O(log(n * m))
           - Space Complexity: O(1)
           - Treat the 2D matrix as a 1D sorted array
        */
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Convert 1D index to 2D row & column
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false; // Target not found
    }
};
