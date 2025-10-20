#include <vector>

/// @brief 
//Key idea was to lookup from behind (starting from the highest values in both vectors)
//so there would not be any need for moving everything 1 place behind
//for example, if we started from the front and had the following situation:
//nums1 = [4,5,7,0,0,0], nums2 = [1,2,3]
//when placing "1" in nums1, we would have to move "4" and everything after it to the right
//(and also pop overflow element).
//If we start from behind, we can just override elements that don't hold any significance (zeros)
//We keep track of how many elements we have moved from each vector, to know what is the current
//element we should compare - we are traversing both vectors backwards
//for the same example, it would look like this:
//nums1 = [4,5,7,0,0,0], nums2 = [1,2,3], 3 < 7 => nums1[i = 6] = nums1[m = 3 - moved_1 = 0 - 1]
//nums1 = [4,5,7,0,0,7] nums2 = [1,2,3], 3 < 5 => nums1[i = 5] = nums1[m = 3 - moved_1 = 1 - 1]
//nums1 = [4,5,7,0,5,7] nums2 = [1,2,3], 3 < 4 => nums1[i = 4] = nums1[m = 3 - moved_1 = 2 - 1]
//nums1 = [4,5,7,4,5,7] nums2 = [1,2,3], moved_1 = 3 > m = 3 - 1 
//=> nums1[i = 3] = nums2[m = 3 - moved_2 = 0 - 1]
//nums1 = [4,5,3,4,5,7] ... 
//Time complexity: O(m + n) => challenge solved

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
        }
        if (n != 0)
        {
            int moved_1 = 0;
            int moved_2 = 0;

            for (int i = m + n - 1; i >= 0; i--)
            {
                if (moved_1 > m - 1)
                {
                    nums1[i] = nums2[n - moved_2 - 1];
                    moved_2++;
                    continue;
                }
                else if (moved_2 > n - 1)
                {
                    continue;
                }
                if (nums1[m - moved_1 - 1] > nums2[n - moved_2 - 1])
                {
                    nums1[i] = nums1[m - moved_1 - 1];
                    moved_1++;
                }
                else 
                {
                    nums1[i] = nums2[n - moved_2 - 1];
                    moved_2++;
                }
            }
        }
    }
};