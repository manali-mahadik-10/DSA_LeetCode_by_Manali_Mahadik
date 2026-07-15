class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        if(f.size()==nums.size()){
            return false;
        }
        else{
            return true;
        }
        
    }
};