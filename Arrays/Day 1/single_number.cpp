class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //We intitialized single variable to store answer
        int ans=0; 
        for(int val : nums){
            ans^=val; //Bitwise XOR
        }
        return ans;
    }
};