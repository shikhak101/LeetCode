class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        for start, end in sorted(intervals, key = lambda i:i[0]):
            if result and start <= result[-1][1]:
                prev_start, prev_end = result[-1]
                result[-1] = (prev_start, max(prev_end, end))
            else:
                result.append((start, end))
        return result
                
            
        