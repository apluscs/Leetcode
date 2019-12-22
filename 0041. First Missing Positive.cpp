class Solution {
    public:
        int firstMissingPositive(vector < int > & nums) {
            int N = nums.size();
            for (int i = 0; i != N; i++) {  //nums[i] is not where it's supposed to be 
                while (nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i]) { 
                    int temp = nums[i];
                    nums[i] = nums[temp - 1];
                    nums[temp - 1] = temp; //swap what's here and with where it's supposed to be
                }
            }
            for (int i = 0; i != N; i++)
                if (nums[i] != i + 1) return i + 1; //return first out of place
            return N + 1; //all are where they're supposed to be, return next one in chain
        }
};
