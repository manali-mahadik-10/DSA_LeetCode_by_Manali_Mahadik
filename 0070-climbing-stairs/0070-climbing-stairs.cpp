class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int first = 1;  // Ways to reach step 0
        int second = 1; // Ways to reach step 1

        for (int i = 2; i <= n; i++) {
            int third = first + second; // Total ways for current step
            first = second;             // Shift window forward
            second = third;
        }

        return second;
    }
};