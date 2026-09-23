class Solution {
public:

    // list of strings -encode-> 1 string
    /**
    Index of char in string = position in vector
    followed by 3 digits for how long the word is (0 <= strs[i] < 200)
    traverse (length of word) times the length of 3 digits for the 256 valid ASCII characters 
    ["Hello", "World"] -> 00 005 072 101 108 108 111, 01 005 087 111 114 108 100
    What about double digit positions? -> Constraint is that the length of the array is less than 100 2 digits at most
    
    */
    string encode(vector<string>& strs) { 
        string encodedStrs;
        for (int i = 0; i < strs.size(); i++) {
            string pos = format("{:02d}", i); 
            string strLen = format("{:03d}", strs[i].length());
            encodedStrs += pos;
            encodedStrs += strLen;

            string curStr = strs[i];
            for (int j = 0; j < curStr.size(); j++) {
                string curASCII = format("{:03d}", curStr[j]);
                encodedStrs += curASCII;
            }
        }

        return encodedStrs;
    }

    // ["Hello", "World"] -> 00 005 072 101 108 108 111, 01 005 087 111 114 108 100
    vector<string> decode(string s) {
        vector<string> result;
        /**
        collect the position of the word in the array
        */

        // Using two pointers
        auto leftIt = s.begin(); // To track the left bound
        auto rightIt = s.begin(); // to track the right bound
        while (leftIt != s.end()) {
            // collect the position of the word in the array
            rightIt += 2;
            string wordPos(leftIt, rightIt);
            leftIt += 2;
            cout << wordPos << "\n";

            //break;
            // Collect the length of the word
            rightIt += 3;
            string wordLen(leftIt, rightIt);
            leftIt += 3;
            string word;
            // Build each character in the word
            for (int i = 0; i < stoi(wordLen); i++) {
                rightIt += 3;
                string curr(leftIt, rightIt);
                char letter = stoi(curr);
                word += letter;
                leftIt += 3;
            }
            //cout << word << "\n";
            result.push_back(word);
        }


        // collect the length (i) of the string
        // traverse the string in increments of three (i) times, building the word as you go.
        return result; 


    }
};
