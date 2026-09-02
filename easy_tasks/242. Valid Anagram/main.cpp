#include <string>
#include <algorithm>
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};

//TODO: solve in O(n) time complexity - currently it is O(nlogn)