class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0;
        int right = 0;
        vector<string> ranges;
        if (nums.size() == 0)
        {
            return ranges;
        }
        if (nums.size() == 1)
        {
            ranges.push_back(std::to_string(nums[0]));
            return ranges;
        }
        while (right <= nums.size() - 1)
        {
            if ((long)nums[std::min(right + 1, (int)nums.size() - 1)] - (long)nums[right] == 1) // need to cast them to long because of test case: [-2147483648,0,2,3,4,6,8,9] which causes overflow for int
            {
                right += 1;
            }
            else 
            {
                if (left == right)
                {
                    ranges.push_back(std::to_string(nums[left]));
                }
                else
                {
                    ranges.push_back(std::to_string(nums[left]) + "->" + std::to_string(nums[right]));
                }
                right = std::min(right + 1, (int)nums.size());
                left = right;
            }
        }
        return ranges;
    }
};