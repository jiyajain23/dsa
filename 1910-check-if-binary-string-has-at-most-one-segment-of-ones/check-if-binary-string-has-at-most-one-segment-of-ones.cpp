class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        int seg=0;
        if(s.size()==1 && s[0]=='1') return true;
        for (char st : s) {
            if (st == '1' && flag == true) continue;
            else if (st == '1') {
                flag = true;
                seg+=1;
            } else
                flag = false;
        }
        return seg==1;
    }
};