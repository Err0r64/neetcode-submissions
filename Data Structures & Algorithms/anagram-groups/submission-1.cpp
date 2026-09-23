class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Anagrams will have the same # of chars
        // for each str in the vector count the chars and map them
        map<vector<int>, vector<string>> charFreqMap;
        vector<vector<string>> result;
        for (const auto& s : strs) { // For each string in strs
            vector<int> count(26, 0); // Vector to hold char frequencies
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++; // increment the index corresponding to the char
            }
            charFreqMap[count].push_back(s); // Map the str to this char freq

        }

        for (const auto& pair : charFreqMap) {
            result.push_back(pair.second); // Push all vectors to the returning vector.
        }
        return result;
    }
};
