#include <iostream>
#include <map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> charMap;
        for (char c : s) {
            charMap[c]++;
        } 

        for (char c : t) {
            charMap[c]--;
        }

        for (const auto& [c, i] : charMap) {
            if (i != 0) return false;
        }

        return true;
        

    }
};
