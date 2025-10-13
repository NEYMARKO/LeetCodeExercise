#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> results_caching;

int climbStairs(int n) 
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    if (results_caching.find(n) != results_caching.end())
    {
        return results_caching[n];
    }

    int result = climbStairs(n - 1) + climbStairs(n - 2);
    results_caching[n] = result;
    return result;        
}

int main()
{
    int n = 44;
    std::cout << "Sucessful build\n";
    std::cout << "Result: " << climbStairs(n);
    return 0;
}