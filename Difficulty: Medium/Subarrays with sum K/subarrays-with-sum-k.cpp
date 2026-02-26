class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> mpp;
        int sum=0;
        
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k) count++;
            if(mpp.find(sum-k)!=mpp.end()){
                count+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};