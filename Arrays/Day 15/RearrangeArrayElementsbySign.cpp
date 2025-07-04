// 🚀 Rearrange Array Elements by Sign
// Problem: Rearrange the given array such that positive and negative numbers alternate,
// starting with a positive number. Assume equal number of positives and negatives.

// Approaches:
// 1️⃣ Brute Force: Separate positives and negatives into two arrays and merge alternately. O(n) space, O(n) time.
// 2️⃣ Better: Single pass, filling even indices with positives and odd indices with negatives. O(n) space, O(n) time.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Brute Force Approach
    vector<int> rearrangeArrayBrute(vector<int>& nums) {
        vector<int> pos, neg;
        for (int num : nums) {
            if (num >= 0) pos.push_back(num);
            else neg.push_back(num);
        }

        vector<int> result;
        for (int i = 0; i < pos.size(); ++i) {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }
        return result;
    }

    // ✅ Better Approach (Single Pass with extra array)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int pos = 0, neg = 1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                result[pos] = nums[i];
                pos += 2;
            } else {
                result[neg] = nums[i];
                neg += 2;
            }
        }
        return result;
    }
};

/*
📝 Complexity:
- Time: O(n) for both approaches.
- Space: O(n) extra space for result array.
- Note: It is possible to do in-place with more complex logic, but this is clean and efficient.

🔷 Author: Deepika
🔷 Date: 2025-07-04
*/
