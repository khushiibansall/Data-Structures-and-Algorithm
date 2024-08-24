class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // we have total sum
        int totalSum=0;
        for (int num : nums) {
            totalSum += num;
        }
        // we have the max from the straight away (not circular)
        int maxi = INT_MIN;
        int sum1 = 0;
        for (int num : nums) {
            sum1 += num;
            maxi = max(sum1, maxi);
            if (sum1 < 0)
                sum1 = 0;
        }
        // we want min sum subarray
        int sum2 = 0;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            sum2 = min(nums[i], sum2 + nums[i]);
            mini = min(mini, sum2);
        }
        //circular max sum= totalsum - minsum
        int circularMax= totalSum- mini;
        if(maxi>0) return max(maxi, circularMax);
        else return maxi;
    }
};
