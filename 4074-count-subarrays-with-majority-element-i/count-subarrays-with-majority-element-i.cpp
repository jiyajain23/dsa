class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int tarcount=0;
            for(int j=i;j<n;j++){
                int size=j-i+1;
                if(nums[j]==target) tarcount++;
                if(2*tarcount>size) ans++;
            }
        }
        return ans;
    }
};