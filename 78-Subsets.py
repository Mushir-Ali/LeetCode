class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans = []
        curr = []
        def f(i):
            if i==len(nums):
                ans.append(curr.copy())
                return
            curr.append(nums[i])
            f(i+1)
            curr.pop()
            f(i+1)
        f(0)
        return ans