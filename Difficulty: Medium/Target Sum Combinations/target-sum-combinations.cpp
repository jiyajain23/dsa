class Solution {
  public:
  
    void getComb(vector<int> &arr, int target, int i,set<vector<int>> &ans,vector<int>&ds){
        if(i >= arr.size()) return; 
        if(target==0){
            ans.insert(ds);
            return;
        }
        
        if(target>=arr[i]){
            ds.push_back(arr[i]);
            getComb(arr,target-arr[i],i,ans,ds);
            ds.pop_back();
        }
        getComb(arr,target,i+1,ans,ds);
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        set<vector<int>> ans;
        vector<int>ds;
        
        getComb(arr,target,0,ans,ds);
        vector<vector<int>> final(ans.begin(),ans.end());
        return final;
    }
};