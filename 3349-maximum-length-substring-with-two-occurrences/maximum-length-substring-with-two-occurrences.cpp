class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0}; // Initialize array with all zeros
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a']++;
            
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};