class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 0;
        for(int num : nums)
            high = max(num, high);  // high becomes max of nums (every num/high <= 1)
        while(low <= high){
            int mid = (low + high) >> 1;
            if(able(nums, threshold, mid))
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
    
    bool able(vector<int>& nums, int threshold, double div){
        int res = 0;
        for(int num : nums)
            res += int(ceil(num/div));  // round up the quotient
        return res <= threshold;
    }
};
