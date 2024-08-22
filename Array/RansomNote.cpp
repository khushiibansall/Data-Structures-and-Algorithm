class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomMap;
        unordered_map<char, int> magazineMap;
        for (char ch : ransomNote) {
            ransomMap[ch]++;
        }
        for (char ch : magazine) {
            magazineMap[ch]++;
        }

        for (const auto& pair : ransomMap) {
            int count = pair.second;
            if (magazineMap[pair.first] < count) {
                return false;
            }
        }
        return true;
    }
}
;
