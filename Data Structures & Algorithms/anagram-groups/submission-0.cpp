class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Anagrams will have the same # of chars
        // for each str in the vector count the chars and map them
        map<vector<int>, vector<string>> charFreqMap;
        vector<vector<string>> result;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++;
            }
            charFreqMap[count].push_back(s);

        }

        for (const auto& pair : charFreqMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};
