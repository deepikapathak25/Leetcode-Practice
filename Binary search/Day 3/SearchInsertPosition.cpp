class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        //Brute force
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return n; // target is larger than all elements
        */

        //Binary search
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=n;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=target){
                ans = mid;
                e = mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
    }
};