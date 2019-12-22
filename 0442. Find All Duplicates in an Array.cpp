class Solution {
    public:
        vector < int > findDuplicates(vector < int > & nums) {
            int N = nums.size();
            vector < int > res;
            for (int i = 0; i != N; i++) {
                int pos = nums[i] < 0 ? -nums[i] : nums[i] > N ? nums[i] - N : nums[i]; //decode whatever we did to it
                pos--; //base 0 indexing
                if (nums[pos] > N) {} //do nothing 
                else if (nums[pos] > 0) nums[pos] = -nums[pos]; //mark as seen once
                else nums[pos] = -nums[pos] + N; //pos has been seen already, now twice
            } //3 ranges for nums[i]: neg = i+1 has been seen once, pos but < N = never seen
            for (int i = 0; i != N; i++)
                if (nums[i] > N) res.push_back(i + 1); // > N = seen twice
            return res;
        }
};
