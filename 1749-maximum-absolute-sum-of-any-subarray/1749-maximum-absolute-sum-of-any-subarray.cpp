        class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int n = nums.size();
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        
        // Kadane's algorithm to find max and min subarray sums
        for (int i = 1; i < n; i++) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            minEndingHere = min(nums[i], minEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
            minSoFar = min(minSoFar, minEndingHere);
        }
        
        // The maximum absolute sum is the maximum of the absolute values of maxSoFar and minSoFar
        return max(abs(maxSoFar), abs(minSoFar));
    }
};