class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        
        // heap -> pairs -> min, min
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        unordered_map<int, int> f;
        
        for (int i = 0; i < n; i++) {
            f[a[i]]++;
        }
        
        for (auto i : f) {
            int element = i.first;
            int freq = i.second;
            
            pair<int, int> curr = {freq, element};
            
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }
            
            if (curr.first < pq.top().first) {
                continue;
            }
            
            pq.pop();
            pq.push(curr);
        }
        
        vector<int> res;
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};