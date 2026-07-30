class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0, a=0, l=0, o=0, n=0;
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') b++;
            if(text[i]=='a')a++;
            if(text[i]=='l')l++;
            if(text[i]=='o')o++;
            if(text[i]=='n')n++;
        }
        int T_b=b/1;
        int T_a=a/1;
        int T_l=l/2;
        int T_o=o/2;
        int T_n=n/1;
        return min({T_b,T_a,T_l,T_o,T_n});

    }
};