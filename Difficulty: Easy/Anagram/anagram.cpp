class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if(s1.size()!=s2.size()) return false;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        for(int i=0;i<s1.size();i++){
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        for(auto it:mpp1){
            if(mpp2[it.first]!=it.second) return false;
        }
        return true;
    }
};