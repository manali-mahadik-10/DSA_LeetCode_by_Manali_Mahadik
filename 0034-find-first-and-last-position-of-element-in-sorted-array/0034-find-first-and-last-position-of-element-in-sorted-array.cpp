class Solution {
public:
    int lowerIdx(vector<int>& a, int x) {
    int l=0, r=a.size()-1, ans=a.size();
    while (l<=r) {
        int m=(l+r)/2;
        if (a[m]>=x) ans = m, r = m-1;
        else l = m+1;
    }
    return ans;
}
vector<int> searchRange(vector<int>& a, int t) {
    int l = lowerIdx(a, t), r = lowerIdx(a, t+1)-1;
    return (l<=r && a[l]==t) ? vector<int>{l,r} : vector<int>{-1,-1};
}

};