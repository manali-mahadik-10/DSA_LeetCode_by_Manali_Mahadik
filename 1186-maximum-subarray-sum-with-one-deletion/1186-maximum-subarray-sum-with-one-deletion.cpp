class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int noDel=arr[0];
        int oneDel=0;
        int res=arr[0];

        for(int i=1;i<n;i++){
            int prevNoDel= noDel;
            noDel=max(arr[i], noDel+arr[i]);
            oneDel=max(prevNoDel, oneDel+arr[i]);
            res=max(res, max(noDel, oneDel));
        }
        return res;
    }
};