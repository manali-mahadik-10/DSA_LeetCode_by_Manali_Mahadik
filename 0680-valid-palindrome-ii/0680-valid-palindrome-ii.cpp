class Solution {
public:
    bool ispalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return ispalindrome(s, l, r - 1) || ispalindrome(s, l + 1, r);
            }
        }
        return true;
    }
};