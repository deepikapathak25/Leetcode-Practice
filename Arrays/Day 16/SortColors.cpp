class Solution {
public:
    /**
     * Sorts an array containing only 0s, 1s, and 2s (Dutch National Flag problem).
     * Uses three pointers to sort in-place with O(n) time and O(1) space.
     *
     * @param nums Reference to the vector of integers to sort.
     */
    void sortColors(vector<int>& nums) {
        int red = 0;                 // Pointer for the next position of 0
        int white = 0;               // Current element being processed
        int blue = nums.size() - 1; // Pointer for the next position of 2

        // Process all elements until white crosses blue
        while (white <= blue) {
            if (nums[white] == 0) {
                // Place 0 at the beginning
                swap(nums[white], nums[red]);
                red++;
                white++;
            } 
            else if (nums[white] == 1) {
                // 1 is already in its correct place
                white++;
            } 
            else {
                // Place 2 at the end
                swap(nums[white], nums[blue]);
                blue--;
                // Do NOT increment white here because the swapped-in element is unprocessed
            }
        }
    }
};
