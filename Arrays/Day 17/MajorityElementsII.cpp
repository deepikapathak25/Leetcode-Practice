class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        // Brute force
        int n=nums.size();
        set<int>s;
        vector<int>ans;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] == nums[i]){
                    count++;
                }
            }
            if (count > n / 3)
                s.insert(nums[i]);
        }
        for (int val : s) {
        ans.push_back(val); // Add elements to the vector
        }
        return ans;
        */

        /*
        //Better 
        unordered_map<int, int> mp;
        vector<int> ans;
        int len = nums.size() / 3;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            if (it.second > len) {
                ans.push_back(it.first);
            }
        }
        return ans;
        */

        //Optimized approach : Boyer-Moore voting algo
        int n=nums.size();
        int count1=0, count2=0;
        int person1=0, person2=1;

        for(int num:nums){
            if(num==person1){
                count1++;
            }else if(num==person2){
                count2++;
            }else if(count1==0){
                person1=num;
                count1++;
            }else if(count2==0){
                person2=num;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1=count2=0;
        for(int num:nums){
            if(num==person1){
                count1++;
            }else if(num==person2){
                count2++;
            }
        }
        vector<int> result;
        if(count1>n/3){
            result.push_back(person1);
        }if(count2>n/3){
            result.push_back(person2);
        }

        return result;
    }
};