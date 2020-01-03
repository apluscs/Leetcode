class Solution {  // I think it'll be faster if you loop through different sides instead of different matchsticks
    public:
        bool makesquare(vector < int > & nums) {
            int N = nums.size(), target = 0;
            for (int num: nums) target += num;
            if (target % 4 != 0) return false;
            target /= 4;
            vector < bool > used(N);
            sort(nums.begin(), nums.end());
            return helper(4, 0, target, used, nums);
        }

    bool helper(int count, int curr, int target, vector < bool > & used, vector < int > & nums) {
        if (count == 0) return true;
        int N = nums.size();
        for (int i = 0; i != N; i++) { // third one: don't want to redo duplicates if you already know adding nums[i] to curr will result in false
            if (used[i] || curr + nums[i] > target || i != 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
            used[i] = true;
            if (curr + nums[i] == target && helper(count - 1, 0, target, used, nums))
                return true; // one less target needed
            else if (curr + nums[i] < target && helper(count, curr + nums[i], target, used, nums))
                return true; // not quite up there yet
            used[i] = false;
        }
        return false;
    }
};

class SolutionTLE {
    public:
        bool makesquare(vector < int > & nums) {
            int N = nums.size(), target = 0;
            for (int num: nums) target += num;
            if (target % 4 != 0) return false;
            target /= 4;
            vector < bool > used(N);
            return helper(4, 0, target, used, nums);
        }

    bool helper(int count, int curr, int target, vector < bool > & used, vector < int > & nums) {
        // cout<<curr<<" ";
        if (count == 0) return true;
        int N = nums.size();
        for (int i = 0; i != N; i++) {
            if (used[i] || curr + nums[i] > target) continue;
            used[i] = true;
            if (curr + nums[i] == target && helper(count - 1, 0, target, used, nums)) return true;
            else if (curr + nums[i] < target && helper(count, curr + nums[i], target, used, nums)) return true;
            used[i] = false;
        }
        // cout<<endl;
        return false;
    }
};
