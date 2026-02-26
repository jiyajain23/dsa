class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi=0;
        int curr=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                curr=1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    curr++;
                    x++;
                }
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};