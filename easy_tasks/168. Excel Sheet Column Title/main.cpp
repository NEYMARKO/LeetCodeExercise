#include <string>
class Solution {
public:
    char getChar(int index)
    {
        // return char(65 + (number - 1) % 26); 
        return 'A' + index % 26; 
    }
    std::string convertToTitle(int columnNumber) {
        std::string s;
        while (columnNumber > 0)
        {
            columnNumber -= 1; // 1 needs to be substracted because every character is in range [1, 26] instead of [0, 25]
                            // AB = 28 => [1, 26][1, 26] = 28 => [0, 25][0, 25] = (2 - 1, 8 - 1) => this isn't suppoused to be 17,
                            // but 27 in 1st iteration, and 0 in 2nd (because we are converting 1 by 1 character)
                            // think of it backwards: 
                            // We have 'AB', how can we get it? It obviously contains 2 characters, which means we will have to go through loop 2
                            // times. Both of them are in range [1, 26], which means we have to convert them to [0, 25] range (each one of them has to be substracted by 1
                            //  - each level (26^0, 26^1, 26^2, ..., 26^n) represents 1 character, and each one of them is in wrong range, which means that every time
                            // we move a level, we have to substract 1) 
            s += getChar(columnNumber);
            columnNumber /= 26;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
};