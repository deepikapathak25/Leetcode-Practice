class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Brute force:
        /*int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
            return i;
        }
        return n;*/

        /* Optimized using Sum approach
        int n=nums.size();
        int actual_sum=n*(n+1)/2;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int missing = actual_sum-sum;
        return missing;*/

        /*Optimized using Bit manipulation*/
        int xor1=0, xor2=0;
        int n=nums.size();
        for(int i=0;i<nums.size(); i++){
            xor1^=nums[i];
            xor2^=i;
        }
        xor2^=n;

        return xor1^xor2;
    }
};