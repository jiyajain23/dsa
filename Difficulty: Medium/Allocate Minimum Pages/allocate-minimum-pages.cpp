class Solution {
  public:
    int func(vector<int> &arr, int mid){
        int c=1;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(maxi+arr[i]>mid){
                c++;
                maxi=arr[i];
            }else maxi+=arr[i];
        }
        return c;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int ans=0;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int calc=func(arr,mid);
            if(calc<=k){
                ans=mid;
                high=mid-1;
                
            }else low=mid+1;
        }
        return ans;
    }
};