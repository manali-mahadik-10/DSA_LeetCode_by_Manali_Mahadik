class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;   // how many times each number appears in window
        long long sum = 0;
        long long maxSum = 0;
        int duplicates = 0;             // how many numbers currently appear MORE than once
        int left = 0;                   // left edge of the window

        for (int right = 0; right < nums.size(); right++) {

            // Step 1: add the new number into the window
            sum += nums[right];
            freq[nums[right]]++;
            if (freq[nums[right]] == 2) duplicates++;   // it just became a duplicate

            // Step 2: if window is bigger than k, remove exactly ONE number from the left
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 1) duplicates--;   // no longer a duplicate
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            // Step 3: once window is exactly size k and has zero duplicates, check the sum
            if (right - left + 1 == k && duplicates == 0) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};