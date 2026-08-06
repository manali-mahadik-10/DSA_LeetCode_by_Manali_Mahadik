class Solution {
public:
    int firstoccurence(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
    int lastoccurence(vector<int>& nums, int target){
        int low=0, high=nums.size()-1;
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                res=guess;
                low=guess+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstoccurence(nums, target), lastoccurence(nums, target)};
    }
};