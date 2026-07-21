class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=0;
        int right=0;
        int id=0;
        vector<int> res(m+n);
        while(left<m && right<n){
            if(nums1[left]<=nums2[right]){
                //res.push_back(nums1[left]);
                res[id]=nums1[left];
                left++;
                id++;
            }
            else{
                //res.push_back(nums2[right]);
                res[id]=nums2[right];
                id++;
                right++;
            }
        }
        while(left<m){
            //res.push_back(nums1[left]);
            res[id]=nums1[left];
            id++;
            left++;
        }
        while(right<n){
            //res.push_back(nums2[right]);
            res[id]=nums2[right];
            id++;
            right++;
        }
        //return res;
        for(int i=0;i<m+n;i++){
            nums1[i]=res[i];
        }
    }
};