/**
 * LeetCode Problem: 26. Remove Duplicates from Sorted Array
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 
 * Problem Statement:
 * Given a sorted array nums, remove the duplicates in-place such that 
 * each element appears only once and return the new length.
 * 
 * Author: Deepika Pathak
 * Date: 28th June 2025
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // ✅ Optimal Solution using Two-Pointer Technique
        // Time Complexity: O(n), Space Complexity: O(1)

        if (nums.empty()) return 0;

        int i = 0; // i tracks the index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1; // Total count of unique elements



       /*
       // ❌ Brute Force Solution (Not In-Place)
       // Time: O(n^2), Space: O(n)

          vector<int> temp;
          temp.push_back(nums[0]);

  	  for (int i = 1; i < nums.size(); i++) {
	        bool flag = false;
  	      for (int j = 0; j < temp.size(); j++) {
 	           if (nums[i] == temp[j]) {
  	              flag = true;
   	             break;
 	      	   }
 	      }
    	     if (!flag) {
            	temp.push_back(nums[i]);
             }
          }

         for (int i = 0; i < temp.size(); i++) {
	        nums[i] = temp[i];
         }

         return temp.size();
         */

    }
};
