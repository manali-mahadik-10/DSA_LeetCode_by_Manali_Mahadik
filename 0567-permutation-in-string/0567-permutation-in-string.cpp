class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(int i=0;i<n;i++){
            f1[s1[i]-'a']++;
        }
        int i=0;
        for(int j=0;j<m;j++){
            f2[s2[j]-'a']++;
            if(j-i+1 > n){
                f2[s2[i]-'a']--;
                i++;
            }
            if(j-i+1==n){
                int f=0;
                for(int k=0;k<26;k++){
                    if(f1[k]!=f2[k]){
                        f=1;
                        break;
                    }
                }
                if(f!=1){
                    return true;
                }
            }
        }
        return false;
    }
};