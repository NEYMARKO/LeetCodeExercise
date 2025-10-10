#include <iostream>
#include <string>
#include <math.h>

int determineLowerBound(int x)
{
    int low_bound = 1;
    while (low_bound * low_bound < x / 10)
    {
        low_bound *= 2;
    }
    return low_bound;
}

void correctBounds(const int& last_v_u, int& up_bound, const int& last_v_l, int& low_bound, const int& x)
{
    while(up_bound * up_bound < x)
    {
        up_bound = (up_bound + last_v_u) / 2;
    }

    while(low_bound * low_bound > x)
    {
        low_bound = (low_bound + last_v_l) / 2;
    }
    return;
}

int mySqrt(int x) 
{
    long long lower_bound = determineLowerBound(x);
    long long upper_bound = lower_bound * 2;
    long long center;

    if (x < lower_bound) return x;
    
    while (upper_bound * upper_bound <= static_cast<long long>(x)) upper_bound *= 2;
        
    while(upper_bound - lower_bound > 1)
    {
        center = (lower_bound + upper_bound) / 2;
        //move lower bound up
        if (center * center < x)
        {
            lower_bound = center;
        }
        else if (center * center > x)
        {
            upper_bound = center;
        }
        else
        {
            return center;
        }
    }
    return lower_bound;
}

int main()
{
    int n = 9;
    std::cout << "Result: " << mySqrt(n);
    return 0;
}