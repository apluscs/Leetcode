class Solution {
    public:
        int longestMountain(vector < int > & nums) {
            int res = 0, status = 0, curr = 0, N = nums.size();
            if (N < 3) return 0;
            nums.push_back(nums[N - 1] + 1); //so we don't have to worry about indexing the last num
            for (int i = 0; i != N; i++)
                // cout<<i<<", ";
                if (nums[i + 1] > nums[i]) { //ascending
                    curr++; //already ascending so just keep going
                    if (status == 0) status = 1; //found a mtn
                    else if (status == -1) { //finished the mtn
                        res = max(res, curr);
                        status = curr = 1;
                    }
                } else if (nums[i + 1] < nums[i]) { //descending
                if (status == 1) { //found the peak
                    curr++;
                    status = -1; //start the descent
                } else if (status == -1) curr++; //continue descending
            } else {
                if (status == -1) res = max(res, curr + 1); //only consider curr if you are finishing a mtn
                status = curr = 0; //start anew
            }
            return res;
        }
};
