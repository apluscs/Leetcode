class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        res = []
        for i in range(len(restaurants)):
            rest = restaurants[i]
            if (not veganFriendly or rest[2] == 1) and rest[3] <= maxPrice and rest[4] <= maxDistance:
                
                res.append(rest)
                
        def compare(a: List[int], b: List[int]):
            if a[1] != b[1]:    # by rating
                return b[1] - a[1]
            else:   # then by id
                return b[0] - a[0]

        res.sort(key = cmp_to_key(compare))
        for i in range(len(res)):
            res[i] = res[i][0]  # reduce to just id
        return res
                
