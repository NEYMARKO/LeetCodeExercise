/**
Bad Solution:
class Solution {
public:

    void swapElements(std::vector<int>& nums, int pos1, int pos2)
    {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp; 
    }

    void moveElementToEnd(std::vector<int>& nums, int startIdx, int endIdx)
    {
        for (int i = startIdx; i < endIdx; i++)
        {
            swapElements(nums, i, i + 1);
        }
    }
    void moveZeroes(std::vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] == 0)
            {
                moveElementToEnd(nums, start, end);
                start--; // might have switched places with another 0
                end--;
            }
            start++;
        }
    }
};
*/

/**
Little bit better (but still bad):
class Solution {
public:

    void swapElements(std::vector<int>& nums, int pos1, int pos2)
    {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp; 
    }

    void moveZeroes(std::vector<int>& nums) {
        int zero_pos = -1;
        int current_pos = 0;
        int temp_pos = 0;
        while (current_pos < nums.size())
        {
            if (nums[current_pos] == 0 && zero_pos == -1)
            {
                zero_pos = current_pos;
            }
            else if (nums[current_pos] != 0 && zero_pos != -1)
            {
                swapElements(nums, zero_pos, current_pos);
                // temp_pos = zero_pos;
                // zero_pos = current_pos;
                // current_pos = temp_pos;
                current_pos = zero_pos;
                zero_pos = -1;
            }
            current_pos++;
        }
    }
};

this still has very bad time performance
*/

// IN PROGRESS:
class Solution {
public:

    void swapElements(std::vector<int>& nums, int pos1, int pos2)
    {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp; 
    }

    void moveZeroes(std::vector<int>& nums) {
        int zero_pos = -1;
        int current_pos = 0;
        int temp_pos = 0;
        while (current_pos < nums.size())
        {
            if (nums[current_pos] == 0 && (current_pos < zero_pos || zero_pos == -1))
            {
                zero_pos = current_pos;
            }
            else if (nums[current_pos] != 0)
            {
                swapElements(nums, zero_pos, current_pos);
                temp_pos = zero_pos;
                zero_pos = current_pos;
                current_pos = temp_pos;
                // current_pos = zero_pos;
                // zero_pos = -1;
            }
            current_pos++;
        }
    }
};