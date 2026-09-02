#include <unordered_set>
#include <cmath>

class Solution {
public:
    int generateSquareDigitSumNum(int n)
    {
        int result = 0;
        while(n > 0)
        {
            result += std::pow((n % 10), 2);
            n /= 10;
        }
        return result;
    }
    bool isHappy(int n) {
        std::unordered_set<int> seen_nums;
        while (n != 1)
        {
            // this number has been seen already
            if (seen_nums.find(n) != seen_nums.end())
            {
                return false;
            }
            else
            {
                seen_nums.insert(n);
            }
            n = generateSquareDigitSumNum(n);
        }
        return true;
    }
};