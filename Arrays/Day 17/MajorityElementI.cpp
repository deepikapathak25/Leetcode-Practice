class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        // Brute force
        int n=nums.size();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] == nums[i])
                    count++;
            }
            if (count > n / 2)
                return nums[i];
        }
        return {};
        */

        /*
        //Better
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int len = (nums.size()) / 2;
        for (auto it : mp) {
            if (it.second > len) {
                return it.first;
            }
        }
        return {};
        */

        //Optimized : Boyer-Moore voting algo
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};