class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){ return 0;}
        int n=nums.size();
        long long product=1;
        int left=0, count=0;
        for(int right=0;right<n;right++){
            product=product*nums[right];
            while(product>=k){
                product=product/nums[left];
                left++;
            }
            count=count+(right-left+1);
        }
        return count;
    }
};