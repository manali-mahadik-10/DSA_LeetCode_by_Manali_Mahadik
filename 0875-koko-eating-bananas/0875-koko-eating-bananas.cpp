class Solution {
public:
    long fun(vector<int>&piles, int n, int speed){
        long h=0;
        for(int i=0;i<n;i++){
            h=h+piles[i]/speed;
            if(piles[i]%speed!=0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(); int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        int low=1, high=maxi;
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            long hour=fun(piles,n,guess);
            if(hour>h){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};