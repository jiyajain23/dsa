class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int smap[26]={0};
        for(int i=0;i<n;i++){
            smap[s[i]-'a']++;
        }
        string ans="";
        char mid;
        for(int i=0;i<26;i++){
            if(smap[i]==0) continue;
            if(smap[i]!=0){
                for(int j=0;j<smap[i]/2;j++) ans.push_back(char(i+'a'));
            }
            if(smap[i]%2!=0) mid=char(i+'a');
        }
        string right=ans;
        reverse(right.begin(),right.end());
        if(mid) ans.push_back(mid);
        ans.append(right);
        return ans;
    }
};