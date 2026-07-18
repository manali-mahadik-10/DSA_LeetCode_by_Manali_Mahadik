class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0 , one =0 , res =0 ; 
        map<int , int >f ; 
        for(int i =0 ; i<nums.size() ; i++){
            if(nums[i]==0) zero++; 
            else one++; 
            int diff=zero-one; 
            if(diff==0){
                res = max(res ,i+1);
            }
            else if(f.count(diff)==0){
                f[diff]=i ; 

            }
            else {
                int len = i-f[diff]; 
                res=max(res , len);
            }
        }
        return res ;
    }
};