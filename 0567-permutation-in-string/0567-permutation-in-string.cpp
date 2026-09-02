class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        if(arr1==arr2) return true;
        int left=0;
        for(int i=n1;i<n2;i++){
            arr2[s2[i]-'a']++;
            arr2[s2[left]-'a']--;
            left++;
            if(arr1==arr2) return true;
        }
        return false;
    }
};