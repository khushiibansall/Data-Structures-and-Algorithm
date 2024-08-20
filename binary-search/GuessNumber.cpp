
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2; // To avoid overflow, use this
                                              
            int result = guess(mid);

            if (result == 0) {
                return mid; // The correct number is found
            } else if (result == 1) {
                low = mid + 1; // The target number is higher
            } else {
                high = mid - 1; // The target number is lower
            }
        }

        return -1;
    }
};
