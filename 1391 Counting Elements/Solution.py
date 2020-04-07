class Solution:
    def countElements(self, arr: List[int]) -> int:
        c = collections.Counter(arr)
        return sum([1 for x in arr if x+1 in arr])