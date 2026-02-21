class Solution {
public:
    bool isPrime(int x){
        if(x<2) return false;
        if(x==2 || x==3) return true;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int bits(int x){
        int c=0;
        while(x>1){
            if(x%2==1) c++;
            x=x/2;
        }
        if(x==1) c++;
        return c;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int b=bits(i);
            if(isPrime(b)) ans++;
        }
        return ans;
    }
};