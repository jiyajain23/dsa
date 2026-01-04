class Solution {
public:
    bool isprime(int x){
        if(x<2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n:nums){
            int cr=round(cbrt(n));
            if(cr*cr*cr==n && isprime(cr)){
                ans+=1+n+cr+cr*cr;
                continue;
            }

            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    int j=n/i;
                    if(j!=i && isprime(i) && isprime(j)){
                        ans+=1+n+i+j;
                    }
                }
            }
        }
        return ans;
    }
};