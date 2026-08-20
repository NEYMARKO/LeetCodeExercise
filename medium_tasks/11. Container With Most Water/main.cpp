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
            left++;
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