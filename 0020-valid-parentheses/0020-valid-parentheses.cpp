class Solution {
public:
    string s;
    size_t i;
    bool recursion() {
        if (i == s.size()-1) {
            return false;
        }

        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            return false;
        }

        if (s[i] == '(') {
            i++;
            while (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                if (!recursion()) {
                    return false;
                }

                i++;
            }

            return (s[i] == ')');
        }

        if (s[i] == '[') {
            i++;
            while (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                if (!recursion()) {
                    return false;
                }

                i++;
            }

            return (s[i] == ']');
        }

        i++;
        while (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            if (!recursion()) {
                return false;
            }

            i++;
        }

        return (s[i] == '}');
    }

    bool isValid(string s) {
        this->s = s;
        this->i = 0;

        while (this->i < this->s.size()) {
            if (!recursion()) {
                return false;
            }

            this->i++;
        }

        return true;
    }
};