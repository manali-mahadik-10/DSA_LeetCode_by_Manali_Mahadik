class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0; // This will store our final answer
        
        for (int i = 0; i < nums.size(); i++) {
            int digits = 0; // 1. Added a variable to count the digits of the CURRENT number
            
            while (nums[i] != 0) {
                // 2. Simplifed your even/odd check to just count EVERY digit
                if (nums[i] % 2 == 0 || nums[i] % 2 != 0) { 
                    digits++; 
                    nums[i] = nums[i] / 10;
                }
            }
            
            // 3. After the while loop finishes, check if the total digits are even
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};