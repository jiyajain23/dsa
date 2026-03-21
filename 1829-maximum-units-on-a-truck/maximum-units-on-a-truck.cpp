class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
            return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize==0) return ans;
            if(truckSize>=boxTypes[i][0]){
                truckSize-=boxTypes[i][0];
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
            }else{
                int num=truckSize;
                ans+=num*boxTypes[i][1];
                return ans;
            }
        }
        return ans;
    }
};