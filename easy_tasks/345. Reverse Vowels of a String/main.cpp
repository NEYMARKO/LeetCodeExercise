#include <string>
#include <cctype>
#include <iostream>
#include <unordered_set>
class Solution {
public:
    bool isVowel(const std::unordered_set<char>& vowels, const char c)
    {
        char lowered = static_cast<char>(std::tolower(c));
        return vowels.find(lowered) != vowels.end();
    }
    std::string reverseVowels(std::string s) {
        if (s.length() <= 1)
        {
            return s;
        }
        std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        char* left = &s[0];
        char* right = &s[s.length() - 1];

        // General idea: once you have found vowel on either side, do not move
        // it until the other side has found it's vowel aswell - both sides need to find them
        // so that they could be swapped
        while (left < right)
        {
            if (isVowel(vowels, *left) && isVowel(vowels, *right))
            {
                char temp = *left;
                *left = *right;
                *right = temp;
                left++;
                right--;
                continue;
            }

            if (!isVowel(vowels, *left))
            {
                left++;
            }
            if (!isVowel(vowels, *right))
            {
                right--;
            }
        }
        return s;
    }
};

void main()
{
    Solution sol = Solution();
    std::string s = "IceCreAm";
    sol.reverseVowels(s);
}