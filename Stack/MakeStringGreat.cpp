class Solution {
public:
    string makeGood(string s) {
        string result = "";
        
        for(char &ch : s) {
            // Check if result is not empty and the last character in result and current character form a bad pair
            if(!result.empty() && (ch + 32 == result.back() || ch - 32 == result.back())) {
                result.pop_back(); // Remove the last character from result
            } else {
                result.push_back(ch); // Add the current character to result
            }
        }
        
        return result;
    }
};
