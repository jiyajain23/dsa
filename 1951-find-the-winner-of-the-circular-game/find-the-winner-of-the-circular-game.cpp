class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        int x=0;
        while(q.size()!=1){
            x=(x+1)%k;
            if(x!=0){
                int a=q.front();
                q.push(a);
            }
            q.pop();
        }
        return q.front();
    }
};