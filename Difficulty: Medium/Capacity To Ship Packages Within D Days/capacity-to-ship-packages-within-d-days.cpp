// User function Template for C++

class Solution {
  public:
    
    int days(int arr[],int x,int n){
        int c=1;
        int m=arr[0];
        for(int i=1;i<n;i++){
            if(m+arr[i]>x){
               c++;
               m=arr[i];
            } else m+=arr[i];
        }
        return c;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int maxi=0;
        int low,high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        low=maxi;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int count=days(arr,mid,n);
            
            if(count<=d){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};