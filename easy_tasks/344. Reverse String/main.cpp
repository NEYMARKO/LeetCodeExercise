#include <vector>
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char* left = &s[0];
        char* right = &s[s.size() - 1];
        while (left < right)
        {
            char temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }
};