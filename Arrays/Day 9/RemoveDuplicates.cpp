class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute Force Approach
        //TC=> O(nlogn)+O(n)
        //SC=>O(n)
        set<int> st; //It will store all unique elements from an array
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int index=0;
        // This loop will replace the value of array with values stored in set
        for(auto it:st){
            nums[index]=it;
            index++;
        }
        return index;
    }
};