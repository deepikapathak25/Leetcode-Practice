// LeetCode: Unique Paths
// Problem: Count the number of unique paths from top-left to bottom-right 
//          in an m x n grid, moving only down or right.
// Approach: Combinatorics - Compute C(m+n-2, m-1) = (m+n-2)! / [(m-1)! * (n-1)!]
// Optimized to avoid large factorials by computing C(N, r) iteratively.
// Time Complexity: O(min(m, n))
// Space Complexity: O(1)

class Solution {
public:

    /*
    // Brute-force combinatorics with explicit factorial computation.
    // Not recommended for large inputs because of overflow risk.
    int factorial(int r) {
        int fact = 1;
        for (int i = 1; i <= r; i++) {
            fact *= i;
        }
        return fact;
    }

    int uniquePaths(int m, int n) {
        int totalSteps = m + n - 2;   // Total number of steps
        int downSteps = m - 1;        // Steps down
        int rightSteps = n - 1;       // Steps right

        // Compute: totalSteps! / (downSteps! * rightSteps!)
        int options = factorial(totalSteps) /
                      (factorial(downSteps) * factorial(rightSteps));
        return options;
    }
    */

    // Optimized combinatorics without explicit factorials
    int uniquePaths(int m, int n) {
        int N = m + n - 2;            // Total number of steps
        int r = min(m - 1, n - 1);    // Choose the smaller of down or right moves
        long long res = 1;            // Use long long for intermediate calculations

        // Compute C(N, r) = N! / (r! * (N-r)!) iteratively
        for (int i = 1; i <= r; ++i) {
            res = res * (N - r + i) / i;
        }

        return static_cast<int>(res);
    }
};
