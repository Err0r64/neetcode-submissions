#include <iostream>
#include <map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> charMapS;
        map<char, int> charMapT;
        for (char c : s) {
            charMapS[c]++;
        } 

        for (char c : t) {
            charMapT[c] ++;
        }

        for (const auto& [c, i] : charMapS) {
            if (charMapT.contains(c)) {
                if (i != charMapT[c]) return false;
            } else {
                return false;
            }
        }

        return true;
        

    }
};
