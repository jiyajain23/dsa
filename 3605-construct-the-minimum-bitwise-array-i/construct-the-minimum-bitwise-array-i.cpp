class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int a=-1;
            for(int i=0;i<x;i++){
                if((i | i+1)==x){
                    a=i;
                    break;
                } 
            }
            nums[i]=a;
        }
        return nums;
    }
};