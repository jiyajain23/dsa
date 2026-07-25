class Solution {
public:
    int maxProduct(int n) {
        vector<int> digs;
        while(n>0){
            digs.push_back(n%10);
            n/=10;
        }
        sort(digs.begin(),digs.end(),greater<>());
        return digs[0]*digs[1];
    }
};