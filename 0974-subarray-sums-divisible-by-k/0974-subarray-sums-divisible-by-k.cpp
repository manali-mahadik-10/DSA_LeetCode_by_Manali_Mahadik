class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> f; int freq;
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            int rem = sum % k;
            if (rem < 0) { //edge case when element is negative 
                rem = rem + k;
            }
            if(f[rem]){
                freq=f[rem];
            }
            else{
                freq=0;
            }
            res = res + freq;
            f[rem]++;
        }
        return res;
    }
};