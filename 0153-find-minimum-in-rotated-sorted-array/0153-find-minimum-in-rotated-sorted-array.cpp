class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size();
        int res=0;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]>nums[nums.size()-1]){
                low=guess+1;
            }
            else{
                res=nums[guess];
                high=guess-1;
            }
        }
        return res;
    }
};