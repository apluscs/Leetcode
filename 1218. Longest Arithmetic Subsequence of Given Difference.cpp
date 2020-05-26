class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        unordered_map<int,int> map; // map[num] = length of longest subsequence ending with a value of num
        int res = 0;
        for(int num : nums){
            if(map.count(num-difference))
                map[num] = map[num-difference] + 1;
            else 
                map[num] = 1;   // start the sequence with this num
            res = max(res, map[num]);
        }
        return res;
    }
};
