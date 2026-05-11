class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int it:nums){
            vector<int>temp;
            while(it>=1){
                int n=it%10;
                it=it/10;
                temp.push_back(n);
            }
            for(int i=temp.size()-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};