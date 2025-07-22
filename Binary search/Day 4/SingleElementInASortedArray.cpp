class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        //Brute force
        int n=nums.size();
        for(int i=0;i<n;i+=2){
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return nums[n-1];
        

        //Brute force Approach2
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        for(auto& it:m){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
        

        // Bit manipulation
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;
        */

        //Binary search
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;

            if (mid % 2 == 1) mid--;
            if(nums[mid]==nums[mid+1]){
                s=mid+2;
            }else{
                e=mid;
            }
        }
        return nums[s];
    }
};