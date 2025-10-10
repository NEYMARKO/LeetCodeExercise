#include <iostream>
#include <string>
#include <algorithm>

char add(const int& a, const int &b, const int &carry)
{
    // carry = (a + b + carry) / 2; 
    return char((a + b + carry) % 2 + 48);
}

std::string addBinary(std::string a, std::string b) {
    int i_a, i_b;
    int result_len = std::max(a.length(), b.length()) + 1;
    int i = 0;
    int carry = 0;
    std::string result(result_len, 'x');

    while (!a.empty() && !b.empty())
    {
        i_a = a.back() - '0';
        i_b = b.back() - '0';
        result[i] = add(i_a, i_b, carry);
        carry = (i_a + i_b + carry) / 2;
        i++;
        a.pop_back();
        b.pop_back();
    }
    //string cocatenation
    a = a + b;
    
    while(!a.empty())
    {
        i_a = a.back() - '0';
        result[i] = add(i_a, 0, carry);
        carry = (i_a + carry) / 2;
        i++;
        a.pop_back();
    }

    if (carry == 1)
    {
        result[result_len - 1] = '1';
    }

    if (result[result_len - 1] == 'x') result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string s1{"11"};
    std::string s2{"0"};
    std::cout << "Result: " << addBinary(s1, s2);
    return 0;
}