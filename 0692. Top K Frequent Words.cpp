class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        dict = {}
        res = []
        for word in words:
            dict[word] = 1+ (dict[word] if word in dict else 0)
        heap = []
        for key, val in dict.items():
            heapq.heappush(heap, (-val, key))    # push a tuple (frq, word), descending frq
        for i in range(k):
            res.append(heapq.heappop(heap)[1])
        return res
