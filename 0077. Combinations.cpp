class Solution {
public:
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k > n) return res;
        vector<int> curr(k);
        int i = 0;
        while(i != -1){   // iteratively :/
            curr[i]++;
            if(curr[i] > n) i--;    // exhausted all possibilities for this slot
            else if(i == k - 1) res.push_back(curr);
            else{
                i++; 
                curr[i] = curr[i-1];
            }
        }
        return res;
    }
};

class SolutionSLOW {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        if(k > n) return res;
        vector<int> curr;
        helper(n, k, curr);
        return res;
    }
    
    void helper(int n, int k, vector<int>& curr){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        for(int x = curr.empty() ? 1 : curr.back() + 1; x <= n; ++x){
            curr.push_back(x);
            helper(n, k , curr);
            curr.pop_back();
        }
    }
};
