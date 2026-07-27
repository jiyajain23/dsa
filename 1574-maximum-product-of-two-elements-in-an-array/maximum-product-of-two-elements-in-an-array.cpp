class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int smaxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxi){
                smaxi=maxi;
                maxi=nums[i];
            }else if(nums[i]>smaxi){
                smaxi=nums[i];
            }
        }
        return (maxi-1)*(smaxi-1);
    }
};