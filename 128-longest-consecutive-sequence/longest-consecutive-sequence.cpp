class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=1;
        }
       int maxi=0;
       int prev=-1,curr=0;
        for(auto it:mpp){
            if(prev==it.first-1 && curr!=0){
                curr++;
            }else{
                curr=1;
            }
            maxi=max(maxi,curr);
            prev=it.first;
        }
    return maxi;
    }
};