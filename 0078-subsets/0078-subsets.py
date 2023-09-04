class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [[nums[j] for j in range(len(nums)) if i >> j & 1] for i in range(2 ** len(nums))]
        