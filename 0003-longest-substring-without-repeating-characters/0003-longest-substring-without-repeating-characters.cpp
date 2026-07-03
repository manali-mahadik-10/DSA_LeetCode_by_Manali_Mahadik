class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0, high=0, res=INT_MIN, n=s.size();
        unordered_map<char,int> f;
        for(high=0;high<n;high++){
            f[s[high]]++;
            int len=high-low+1;
            while(f.size()<len){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                len=high-low+1;
            }
            res=max(len,res);
        }
        if(res==INT_MIN && s.size()==0){ return 0;}
        if(res==INT_MIN){ return 1;}
        //else if(s.size()==0){ return 0;}
        else{ return res;}
    }
};