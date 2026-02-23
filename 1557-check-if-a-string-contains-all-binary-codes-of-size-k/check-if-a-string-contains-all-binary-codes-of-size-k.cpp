class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<vector<char>> se;
        for(int i=0;i<=(int)s.size() - k;i++){
            vector<char> temp;
            for(int j=i;j<i+k;j++){
                temp.push_back(s[j]);
            }
            se.insert(temp);
        }
        return se.size()==(1<<k);
    }
};