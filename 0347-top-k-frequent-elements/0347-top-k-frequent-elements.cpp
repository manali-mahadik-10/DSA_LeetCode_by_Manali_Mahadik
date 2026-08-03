class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==(int)nums.size()) return nums;
        
        unordered_map<int,int> count;
        for(int num:nums){
            count[num]++;
        }
        
        vector<pair<int,int>> freq;
        for(auto it=count.begin(); it!=count.end(); ++it){
            freq.push_back(make_pair(it->first, it->second));
        }
        
        sort(freq.begin(), freq.end(), compare);
        
        vector<int> top(k);
        
        for(int i=0; i<k; ++i){
            top[i] = freq[i].first;
        }
        
        return top;
    }
    
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }
};