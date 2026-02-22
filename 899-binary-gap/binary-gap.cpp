class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = 0;
        int maxi = 0;

        while (n > 0) {
            if (n % 2 == 1) {
                if (prev != -1) {
                    maxi = max(maxi, curr - prev);
                }
                prev = curr;
            }
            curr++;
            n = n / 2;
        }

        return maxi;
    }
};