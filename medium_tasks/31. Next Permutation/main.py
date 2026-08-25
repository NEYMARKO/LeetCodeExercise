
print("BEFORE SOLUTION")
class Solution:

    def sorted_descendingly(self, start: int, nums: list[int]) -> bool:
        for i in range(start, len(nums) - 1):
            if nums[i+1] > nums[i]:
                return False
        return True

    def reverse_list_inplace(self, nums: list[int], left: int, right: int) -> None:
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if self.sorted_descendingly(0, nums): # in case we got to the last permutation, return everything back to the smallest
            nums.reverse() # reverse elements
            return
        
        max_num = max(nums)
        if nums[1] == max_num and self.sorted_descendingly(1, nums): # find next biggest element and put it in the 1st place (sort the rest)
            # replaceable_idx = 1 if nums[1] >
            current = nums[0] 
            nums.sort()
            curr_elem_idx = [i for i, x in enumerate(nums) if x == current][-1]
            nums[0], nums[curr_elem_idx] = nums[curr_elem_idx], nums[0] 
            nums[0], nums[curr_elem_idx + 1] = nums[curr_elem_idx + 1], nums[0]
            # nums[0], nums[1] = nums[1], nums[0] # replace 1st and 2nd element => permutation is going 1 step higher
            return

        for i in range(1, len(nums) - 1):
            if nums[i + 1] > nums[i]:
                temp = nums[i]
                nums[i] = nums[i+1]
                nums[i+1] = temp
                break
        

def main():
    print("HERE")
    sol = Solution()
    perm = [2, 1, 3, 4]
    perm = [2, 3, 1]
    perm = [3, 2, 1, 4]
    perm = [2, 4, 3, 1]
    perm = [2, 5, 4, 3, 1]
    perm = [1, 5, 1]
    perm = [1, 1, 5]
    sol.nextPermutation(perm)
    print(perm)

if __name__ == "__main__":
    main()