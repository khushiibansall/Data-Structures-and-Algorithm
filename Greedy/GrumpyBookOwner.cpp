class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int j = 0;
        int tracker = 0;
        int sum = 0;
        while (j < minutes) {
            if (grumpy[j] == 1)
                sum += customers[j];
            j++;
        }
        int maxi = sum;
        int i = 0;
        while (j < customers.size()) {
            if (grumpy[i] == 1)
                sum -= customers[i];
            if (grumpy[j] == 1)
                sum += customers[j];
            if (sum > maxi) {
                maxi = sum;
                tracker = i + 1;
            }
            i++;
            j++;
        }
        int total = 0;
        for (int a = 0; a < customers.size(); a++) {
            if (grumpy[a] == 0 || (a >= tracker && a < tracker + minutes)) {
                total += customers[a];
            }
        }

        return total;
    }
};
