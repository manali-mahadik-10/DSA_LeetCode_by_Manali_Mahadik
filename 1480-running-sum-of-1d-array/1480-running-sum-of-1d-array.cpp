class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size()); int sum=0;
        for(int i=0;i<nums.size();i++){
            ans[i]=sum+nums[i];
            sum=ans[i];
            //i++;
        }
        return ans;
    }
};