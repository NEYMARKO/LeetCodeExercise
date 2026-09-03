#include <vector>
#include <unordered_set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>* larger_list = (nums1.size() > nums2.size() ? &nums1 : &nums2);
        std::vector<int>* smaller_list = (nums1.size() > nums2.size() ? &nums2 : &nums1);
        std::unordered_set<int> larger_set(larger_list->begin(), larger_list->end());
        std::vector<int> intersection;

        for (int n : *smaller_list)
        {
            if (larger_set.find(n) != larger_set.end())
            {
                intersection.push_back(n);
                larger_set.erase(n);
            }
        }
        return intersection;
    }
};