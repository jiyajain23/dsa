class Solution {
  public:
    typedef long long int ll;

    long long int minValue(vector<int> &arr1, vector<int> &arr2) {
        // code here
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int n=arr1.size();
        long long int ans =0;
        for(int i=0;i<n;i++){
            long long int a=(long long int) arr1[i]*arr2[n-i-1];
            ans+=a;
        }
        return ans;
    }
};