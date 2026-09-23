class Solution {
public:
    bool isPalindrome(string s) {

        string clean;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                //cout << char(tolower(s[i]));
                clean += char (tolower(s[i]));
            }
        }

        int left = 0;
        int right = clean.size() - 1;
    
        while(left < right) {
            if(char(tolower(clean[left])) != char(tolower(clean[right]))) return false;
            left++;
            right--;
        }
        return true;
    }

    


};
