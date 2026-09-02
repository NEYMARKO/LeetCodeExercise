#include <cmath>
#include <string>
class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        std::reverse(columnTitle.begin(), columnTitle.end());
        int base = 1;
        int result = 0;
        for (auto& c : columnTitle)
        {
            result += (c - 'A' + 1) * std::pow(26, base - 1);
            base += 1;
        }
        return result;
    }
};