class Solution {
private:
    bool isPalindrome(string s, int i, int n){
        if(i>n/2) return true;
        if(s[i]!=s[n-i]) return false;
        return isPalindrome(s,i+1,n);
    }
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s=to_string(x);
        return isPalindrome(s,0,s.length()-1);
    }
};