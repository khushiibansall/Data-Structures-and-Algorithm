class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> original = nums; // Save original array
        unordered_map<int, vector<int>> index; // Store all indices for each value
        int i = 0;
        for (int num : nums) {
            index[num].push_back(i);
            i++;
        }
        
        sort(nums.begin(), nums.end());
        int j = nums.size() - 1;
        vector<int> topK;
        while (k != 0) {
            topK.push_back(nums[j]);
            k--;
            j--;
        }
        
        // 1. now make a vector result
        // 2. make an array of same size as nums
        // also check the index of the topK elements from the map and make the
        // element at index that are not topK 0. and that are topK 1 in array of
        // same size. basically a boolean array to keep track
        // 3. traverse the nums and array and push back in result all the non zero
        // values
        vector<int> result;
        vector<int> isTopK(nums.size(), 0);
        
        for (int val : topK) {
            if (!index[val].empty()) {
                int idx = index[val].back(); // Get the last available index
                isTopK[idx] = 1;
                index[val].pop_back(); // Remove the used index to handle duplicates
            }
        }
        
        i = 0;
        for (int num : original) { // Use original array to preserve order
            if (isTopK[i]) 
                result.push_back(num);
            i++;
        }
        
        return result;
    }
};
