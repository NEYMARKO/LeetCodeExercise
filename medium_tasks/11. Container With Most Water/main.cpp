#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height)
{
    int max_area = 0;
    int container_height = 0;
    int container_width = 0;

    int *left = &height[0];
    int *right = &height[height.size() - 1];

    while (left < right)
    {
        container_height = std::min(*left, *right);
        container_width = right - left; // because array idx is starting from 0
        max_area = std::max(container_height * container_width, max_area);
        if (*left > *right)
        {
            right--;
        }
        else if (*right > *left)
        {
            left++;
        }
    
        else
        {
            left++; // when both heights area equal it doesn't matter what pointer you are moving
            //because you will always get a wors water capacity. This is true because you are keeping 
            // the height constraint bud reducing the width. So if it is a better answer it must be in both
            // ranges [i + 1, j] and [i, j - 1]. IF it is in both ranges it is in the intersection so it is in 
            //[i + 1, j -1] which leads to the fact that, when you have equal heights, you can move any of the pointers.
        }
    }
    return max_area;
}

void main()
{
    std::vector<int> height{1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(height);
    return;
}