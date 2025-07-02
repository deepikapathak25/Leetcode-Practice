// Function to find the leaders in the array
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();

        /************ Brute Force Approach ************
         * Time Complexity: O(n^2)
         * Space Complexity: O(n) for storing leaders
         * Logic: For each element, check all elements to its right
        **********************************************/
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                ans.push_back(arr[i]);
            }
        }
        return ans;

        /*
        /************ Optimized Approach ************
         * Time Complexity: O(n)
         * Space Complexity: O(n) for storing leaders
         * Logic: Traverse from right to left and track max so far
        **********************************************
        vector<int> ans;
        int maxi = arr[n - 1];
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxi) {
                maxi = arr[i];
                ans.push_back(arr[i]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
        */
    }
};
