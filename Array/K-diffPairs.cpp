class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> values;
    int len = 0;
    
    for (int num : nums) {
        if (k == 0) {
            if (values[num] == 1) {
                len++;
            }
        } else {
            if (values.find(num) == values.end()) {
                if (values.find(num + k) != values.end()) {
                    len++;
                }
                if (values.find(num - k) != values.end()) {
                    len++;
                }
            }
        }
        values[num]++;
    }
    
    return len; }};
