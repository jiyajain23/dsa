class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r, ans = 0;
        vector<int> mpp(3, 0);
        for (r = 0; r < s.size(); r++) {
            mpp[s[r] - 'a']++;
            while (mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0) {
                ans += s.size()-r;;
                mpp[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
    }
};