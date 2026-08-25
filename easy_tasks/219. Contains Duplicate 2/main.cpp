#include <unordered_map>

/**
 * Idea: Use a hash map to store each value's most recent index.
 * As I iterate through the array, I check whether the current value has appeared before.
 * 
 * If it hasn't, store its current index.
 * If it has, calculate the distance between the current index and its most recent previous index.
 * If that distance is <= k, a valid nearby duplicate exists, so return true.
 * If the distance is > k, the previous occurrence is too far away to matter anymore, so update the map with the current index.
 * Because the map always stores the most recent occurrence of each value, I only need to compare the current index with that one position.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> elem_pos_map;
        for (int i = 0; i < nums.size(); i++)
        {
            // check if element exists in hashmap
            if (elem_pos_map.find(nums[i]) != elem_pos_map.end())
            {
                // override once you have passed k elements => if element difference is k, value is allowed to be overriden
                // `i` is always going to be larger than anything written in elem_pos_map (because those values have
                // been written previous to i being processed). Since difference between 2 same values can't be more than k,
                // we can just override key whose value (position) is larger than k
                if (i - elem_pos_map[nums[i]] > k)
                {
                    elem_pos_map[nums[i]] = i;
                }
                else 
                {
                    return true;
                }
            }
            else
            {
                elem_pos_map[nums[i]] = i;
            }
        }
        return false;
    }
};