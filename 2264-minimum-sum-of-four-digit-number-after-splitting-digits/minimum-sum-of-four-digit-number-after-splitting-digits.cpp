class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while (num > 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        int a = digits[0] * 10 + digits[3];
        int b = digits[1] * 10 + digits[2];
        return a + b;
    }
};