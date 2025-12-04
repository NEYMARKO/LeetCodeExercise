#include <iostream>
#include <string>

class Solution {
public:
    void cleanString(std::string& s)
    {
        char c;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            c = s[i]; 
            if (c >= 'A' && c <= 'Z')
            {
                s[j++] = c + ('a' - 'A');
            }
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            {
                s[j++] = c;
            }
        }
        s.resize(j);
    }
    bool isPalindrome(std::string s) {
        cleanString(s);
        if (s.size() == 0 || s.size() == 1) return true;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
};