class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int pivot = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[n - 1]) {
                low = mid + 1;
            } else {
                pivot = mid;
                high = mid - 1;
            }
        }

        int low1 = 0, high1 = pivot - 1;

        while (low1 <= high1) {
            int mid = (low1 + high1) / 2;

            if (nums[mid] > target)
                high1 = mid - 1;
            else if (nums[mid] < target)
                low1 = mid + 1;
            else
                return mid;
        }

        int low2 = pivot, high2 = n - 1;

        while (low2 <= high2) {
            int mid = (low2 + high2) / 2;

            if (nums[mid] > target)
                high2 = mid - 1;
            else if (nums[mid] < target)
                low2 = mid + 1;
            else
                return mid;
        }

        return -1;
    }
};