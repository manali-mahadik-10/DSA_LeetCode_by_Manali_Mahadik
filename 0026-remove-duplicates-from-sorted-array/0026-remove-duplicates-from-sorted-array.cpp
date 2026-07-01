class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cm=1;
        int ofc=0;
        int unique=1;
        int n=nums.size();
        while(cm<n){
            if(nums[cm]==nums[cm-1]){ cm++; continue;}
            unique++;
            nums[ofc+1]=nums[cm];
            ofc++;
            cm++;
        }
        return unique;

    }
};