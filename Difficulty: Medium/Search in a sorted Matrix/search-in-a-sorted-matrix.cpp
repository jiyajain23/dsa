class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=(m*n)-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            int r=mid/n;
            int c=mid%n;
            if(mat[r][c]==x) return true;
            else if(mat[r][c]<x) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};