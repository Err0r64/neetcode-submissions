#include <iostream>
#include <map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> charMap;
        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]]++;
            charMap[t[i]]--;

        }

        for (const auto& [c, i] : charMap) {
            if (i != 0) return false;
        }

        return true;
        

    }
};
