class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=1;i<=s.size();i++){
            int add='z'-s[i-1]+1;
            ans+=(add*i);
        }
        return ans;
    }
};