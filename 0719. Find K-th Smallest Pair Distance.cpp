class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size(), low = 0, high = nums[N-1] - nums[0];
        while(low <= high){
            int mid = int((long(low) + high) / 2);
            int count = count_le_dists(mid, nums);
            if(count < k)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return low;
    }
    
    int count_le_dists(int cand, vector<int>& nums){    // returns #pairs whose distance is <= cand
        int res = 0, i = 0, N = nums.size(), j = 1; // start in top left corner
        while(i != N){
            j = max(j, i + 1);  // in case j <= i
            while(j != N && nums[j] - nums[i] <= cand)  // find rightmost j such that nums[j] - nums[i] is > cand
                j++;
            res += j - i - 1;   // want range from [i + 1, j - 1]
            i++;    // j doesn't have to start all the way back at i + 1 because if we know 
            // nums[current j] - nums[next i] must be <= nums[current j] - nums[current i] (since nums[next i] is >= nums[current i]). 
            // Since the next diff <= current diff, we don't have to worry about anything coming before j in next row 
            // (will only make the diff smaller, which we don't care about)
        }
        return res;
    }
};
