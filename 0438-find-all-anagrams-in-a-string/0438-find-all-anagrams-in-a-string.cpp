class Solution {
   bool isAnagram(string currentwindow, string p) {
   
    if (currentwindow.length() != p.length()) {
        return false;
    }

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for (int i = 0; i < currentwindow.length(); i++) {
        count1[currentwindow[i] - 'a']++;
        count2[p[i] - 'a']++;
    }

    if (count1 == count2) {
        return true;
    }
    
    return false; 
}
    
    public :
    vector<int> findAnagrams(string s, string p) {
        vector<int>result ;
      int k = p.length();
      int left = 0;
    if( k > s.length() )return result;
      for( int right = 0 ; right < s.length() ; right++){
           if( right - left + 1 == k){

           string currentwindow = s.substr( left , k);
           if( isAnagram( currentwindow , p)){
                   result.push_back(left);
           }
           left++;
           }
      }
      return result ;
    }
};