class Solution {
    public:
        vector < int > findDisappearedNumbers(vector < int > & nums) {
            vector < int > res;
            int N = nums.size();
            for (int i = 0; i != N; i++) {
                if (nums[i] == -1 || nums[i] == i + 1) continue;
                int j = nums[i] - 1;
                nums[i] = -1; //set this cell to empty (-1)
                while (j >= 0 && nums[j] != j + 1) { //j is where curr is supposed to be
                    int temp = nums[j]; // save what's there
                    nums[j] = j + 1;
                    j = temp - 1; //where temp is supposed to be
                }
            }
            for (int i = 0; i != N; i++)
                if (nums[i] != i + 1) res.push_back(i + 1);
            return res;
        }
};
