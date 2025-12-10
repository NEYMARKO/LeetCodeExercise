class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int starting_element = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            starting_element ^= nums[i];
        }
        return starting_element;
    }
};