
//BAD SOLUTION
/**
#include <vector>
#include <algorithm>
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (nums[0] != 0)
        {
            return 0;
        }
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] > 1)
            {
                return nums[i] + 1;
            }
        }
        return nums.size();
    }
};
*/

// Good solution

#include <vector>
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
        }
        int expected_sum = ((nums.size()) * (nums.size() + 1)) / 2; // Gauss method for summing first n elements: n * (n + 1) / 2
        return expected_sum - sum;
    }
};

// 1 element will always be missing from the vector - that's defined by the problem. Max number will always be nums.size() because
// numbers are starting from 0 (not from 1). Numbers are subsequent, which means that we can use Gauss law to determine what would be 
// sum if all elements were present in the vector. We can substract that value with actual sum of values in vector, and we will get missing element

/**
 * Examples:
 * nums = [0,1]
    Output: 2
 * 
 * 
 * nums = [3,0,1]
    Output: 2

*/