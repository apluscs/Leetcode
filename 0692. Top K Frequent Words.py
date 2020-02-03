# how to define your own custom comparator for heapq (priority queue functionality) in python3
class Element:
    def __init__(self, count, word):
        self.count = count
        self.word = word
        
    def __lt__(self, other):
        if self.count == other.count:
            return self.word > other.word   # if two words have the same frq, the larger one lexicographically gets pushed out first
        return self.count < other.count # lowest frequency at the bottom
    
    def __eq__(self, other):    # another function you need to fill in I guess
        return self.count == other.count and self.word == other.word

class Solution(object): # another strategy: only maintain top k
    def topKFrequent(self, words, k):   
        counts = collections.Counter(words)   
        
        freqs = []
        heapq.heapify(freqs)
        for word, count in counts.items():
            heapq.heappush(freqs, (Element(count, word), word)) # tuple, first is just used for ordering
            if len(freqs) > k:  # beyond top k elements
                heapq.heappop(freqs)
        
        res = []
        for _ in range(k):
            res.append(heapq.heappop(freqs)[1])
        return res[::-1]    # reverse it
    

class Solution2:
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
