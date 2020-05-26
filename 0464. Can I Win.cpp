class Solution {
public:

    unordered_map<string, bool> map;
    bool canIWin(int N, int desiredTotal) {
        map.clear();
        int sum = 0;
        vector<int> nums(N);
        for(int i = 1; i <= N; ++i){
            nums[i-1] = i;
            sum += i;
        }
        if(sum < desiredTotal) return false;    // need this because can neither person can win
        return helper(nums, desiredTotal);
    }
    
    bool helper(vector<int>& nums, int goal){
        string id = list_to_string(nums);
        
        if(map.count(id)) return map[id];   // don't recalculate this because you can just get what you calculated before
        // if(nums.empty()){
        //     map[id] = false;
        //     return false;
        // }
        if(nums.back() >= goal){
            map[id] = true;
            return true;
        }
        for(int i = 0; i != nums.size(); ++i){
            int curr = nums[i];
            nums.erase(nums.begin() + i);
            if(!helper(nums, goal - curr)){ // partner will lose
                nums.insert(nums.begin() + i, curr);
                map[id] = true;
                return true;    // so you can win
            }
                
            nums.insert(nums.begin() + i, curr);
        }    
        map[id] = false;    // partner wins everytime
        return false;
        
    }
    
    string list_to_string(vector<int>& nums){
        string res = "";
        for(int num : nums)
            res += to_string(num) + "-";
        return res;
    }
};


