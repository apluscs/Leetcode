class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, N = nums.size();
        while(i != N && nums[i] != 0)
            i++;    // i is at first zero
        j = i + 1;  // skip all nonzeros before i
        while(i != N && j < N){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                while(i != N && nums[i] != 0)
                    i++;    // find next 0 we can fill in; i <= bc nums[j] is a 0, which would cause the while loop's condition to break
            }
            j++;
        }
        
    }
};
