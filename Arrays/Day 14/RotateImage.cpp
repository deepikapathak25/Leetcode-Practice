// 🔷 LeetCode: Rotate Image (90 degrees clockwise)
// Problem: Given an n x n 2D matrix, rotate it 90 degrees clockwise in-place.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        /*
        // Approach 1: Extra Space
        // Create a temporary matrix and place each element at its rotated position.
        vector<vector<int>> temp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = temp;
        // Time Complexity: O(n^2)
        // Space Complexity: O(n^2) - extra matrix
        */

        // Approach 2: In-place rotation using transpose + reverse
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        // Time Complexity: O(n^2)
        // Space Complexity: O(1) - in-place
    }
};
