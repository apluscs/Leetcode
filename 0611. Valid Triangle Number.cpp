class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, N = nums.size();  
        for(int i = N - 1; i >= 2; --i){    // nums[i] is the target
            int low = 0, high = i - 1;
            while(low < high){
                if(nums[low] + nums[high] > nums[i]){
                    res += high - low;  // everything between low and high 
                    high--;
                } else {
                    low++;
                }
            }
        }
        return res;
    }
    
};
