class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        heap = []
        events.sort()
        day = events[0][0]
        i=0
        ans = 0
        n = len(events)
        while len(heap) or i<n:
            while i<n and events[i][0]==day:
                heapq.heappush(heap,events[i][1])
                i+=1
            if len(heap) and heap[0]>=day:
                ans+=1
                heapq.heappop(heap)
            day+=1
            while len(heap) and heap[0]<day:
                heapq.heappop(heap)
        return ans
        