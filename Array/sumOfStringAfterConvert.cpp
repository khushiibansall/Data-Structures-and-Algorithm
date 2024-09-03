class Solution {
public:
    int getLucky(string s, int k) {
        string sum;
        for (char ch : s) {
            int value = ((ch - 'a') + 1);
            sum += to_string(value);
        }
        int num = 0;
        for (char ch : sum) {
            num += ch - '0'; // Convert char to int and accumulate
        }
        while (k>1) {
            int sum2 = 0;
            while (num > 0) {
                int digit = num % 10;
                sum2 += digit;
                num = num / 10;
            }
            num = sum2;
            k--;
        }
        return num;
    }
};
