class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> fri;
        for(int a:friends){
            fri.insert(a);
        }
        vector<int> ans;
        for(int i=0;i<order.size();i++){
            if(fri.count(order[i])>0){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};