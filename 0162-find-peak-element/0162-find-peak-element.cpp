class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=nums.size()-1;
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(guess<n-1 && nums[guess]<nums[guess+1]){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};