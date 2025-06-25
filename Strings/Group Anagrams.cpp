class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (auto& word : strs) {
            string key = word;
            sort(key.begin(), key.end());  // sort the characters
            anagramGroups[key].push_back(word);  // group by sorted key
        }

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);  // collect all groups
        }

        return result;
    }
};
