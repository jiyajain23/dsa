class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> fri(friends.begin(),friends.end());
        vector<int> ans;
        for(int i=0;i<order.size();i++){
            if(fri.contains(order[i])){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};