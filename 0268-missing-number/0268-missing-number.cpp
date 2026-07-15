class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int left=0; int right=n-1;
        for(int i=0;i<n;i++){
            if(left==nums[i]){
                left++;
                continue;
            }
            if(left!=nums[i]){
                return left;
            }
        }
        return left;
    }
};