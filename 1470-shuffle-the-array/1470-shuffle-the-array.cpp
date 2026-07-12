class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int num1=n;
        vector<int> arr1(num1);
        vector<int> arr2(num1);
        for(int i=0;i<num1;i++){
            arr1[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            arr2[i]=nums[n+i];
        }
        int low=0; int high=0; int p=0;
        while(low!=n && high!=n){
            nums[p]=arr1[low];
            low++;
            p++;
            nums[p]=arr2[high];
            high++;
            p++;
        }
        while(low!=num1){
            nums[p]=arr1[low];
            low++;
            p++;
        }
        while(high!=n){
            nums[p]=arr2[high];
            high++;
            p++;
        }
        return nums;

    }
};