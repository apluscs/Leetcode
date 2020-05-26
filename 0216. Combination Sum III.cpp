class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vector<int> curr;
        help(k, n, 1, curr);
        return res;
    }
    
    void help(int k, int target, int start, vector<int>& curr){
        if(target == 0){
            if(curr.size() == k)
                res.push_back(curr);
            return;
        }
        for(int i = start; i != 10; ++i){
            if(i > target) break;
            curr.push_back(i);
            help(k, target - i, i + 1, curr);
            curr.pop_back();
        }
    }
};
