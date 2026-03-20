class Solution {
  public:
    void subs(vector<int>& arr,vector<int> &ds,vector<vector<int>> &ans,int i){
        if(i==arr.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[i]);
        subs(arr,ds,ans,i+1);
        ds.pop_back();
        subs(arr,ds,ans,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int> ds;
        vector<vector<int>> ans;
        subs(arr,ds,ans,0);
        
        return ans;
    }
};