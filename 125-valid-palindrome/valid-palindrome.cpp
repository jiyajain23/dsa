class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" ") return true;
        int l=0,r=s.size()-1;
        while(l<=r){
            s[l]=tolower(s[l]);
            s[r]=tolower(s[r]);
            if(s[l]==' '  || !isalnum(s[l])) {
                l++;
                continue;
            }
            if(s[r]==' ' || !isalnum(s[r])) {
                r--;
                continue;
            }

            if(s[l]!=s[r]) return false;
            l++;
            r--;

        }
        return true;
    }
};