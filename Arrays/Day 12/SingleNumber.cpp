class Solution {
public:
    int singleNumber(vector<int>& nums) {

        /* 🐢 Brute Force Approach
           Time: O(n^2), Space: O(1)
           For every element, count how many times it appears.
        */
        /*
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                return nums[i];
            }
        }
        return -1;
        */

        /* 🧠 Better Approach using Hash Map
           Time: O(n), Space: O(n)
           Count frequencies of each element.
        */
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto& pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1;

        /* ⚡ Optimal Approach using XOR
           Time: O(n), Space: O(1)
           XOR cancels out duplicates, leaving the unique number.
        */
        /*
        int single = 0;
        for (int i = 0; i < nums.size(); i++) {
            single ^= nums[i];
        }
        return single;
        */
    }
};
