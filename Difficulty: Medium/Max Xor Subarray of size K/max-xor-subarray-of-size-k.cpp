class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        if(k>arr.size())  return -1;
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<k;i++){
            sum^=arr[i];
        }
        maxi=max(sum,maxi);
        for(int i=k;i<arr.size();i++){
            sum^=arr[i-k]^arr[i];
            maxi=max(sum,maxi);
        }
        
        return maxi;
    }
};