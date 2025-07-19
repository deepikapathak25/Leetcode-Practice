//Brute Force
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (target == nums[i]) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        return {first, last};
    }
};




//Optimized
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        int first=-1;
        int last=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                first=mid;
                e=mid-1;
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }

        s=0, e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                last=mid;
                s=mid+1;
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }

        return {first,last};
    }
};