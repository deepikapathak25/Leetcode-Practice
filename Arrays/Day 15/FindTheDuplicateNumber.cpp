/*
    🚀 Problem: Find the Duplicate Number
    ------------------------------------
    Given an array `nums` containing `n + 1` integers where each integer is in the range [1, n] inclusive,
    return the duplicate number.

    The array contains only one duplicate number, but it could be repeated more than once.

    ✅ Constraints:
    • You must not modify the array.
    • Use only constant extra space.
    • Time complexity less than O(n²) preferable.

    --------------------------------------------------------------

    🧪 Approaches:
    -------------------------------------
    1️⃣ Brute Force: (commented below)
        • Use an unordered_map to count frequency of each number.
        • Return the first number whose frequency > 1.
        • Time: O(n), Space: O(n)

    2️⃣ Optimized: Floyd's Cycle Detection
        • Treat array as a linked list where `next = nums[current]`.
        • There must be a cycle because of the duplicate.
        • Use slow & fast pointers to find the meeting point, then find entrance of cycle.
        • Time: O(n), Space: O(1)

*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        /*
        // 🔷 Approach 1: Brute Force with HashMap
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (auto& it : freq) {
            if (it.second > 1) {
                return it.first;
            }
        }

        return -1; // no duplicate found (but constraints guarantee there is one)
        */

        // 🔷 Approach 2: Optimized using Floyd’s Cycle Detection

        // Phase 1: Detect Cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];            // move 1 step
            fast = nums[nums[fast]];     // move 2 steps
        } while (slow != fast);

        // Phase 2: Find entrance to cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};
