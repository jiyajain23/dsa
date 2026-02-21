class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int suff=1,pre=1;
        int ans=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            suff=suff*arr[n-i-1];
            pre=pre*arr[i];
            ans=max(ans,max(suff,pre));
        }
        return ans;
    }
};