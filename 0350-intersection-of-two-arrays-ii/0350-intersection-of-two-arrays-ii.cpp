class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int left=0;
        int right=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        while(left<n && right<m){
            if(nums1[left]==nums2[right]){
                res.push_back(nums1[left]);
            
            left++;
            right++;
            }
            else if(nums1[left]<nums2[right]){
                left++;
            }
            else{
                right++;
            }
        }
        return res;

    }
};