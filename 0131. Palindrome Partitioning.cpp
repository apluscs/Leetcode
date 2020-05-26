class Solution {
public:
    vector<vector<string>> res;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        res.clear();
        dp.clear();
        int N = s.length();
        if(N == 0) return res;
        dp.resize(N, vector<bool>(N, true));
        
        for(int gap = 1; gap != N; ++gap){
            for(int i = 0; i + gap != N; ++i){
                int j = i + gap;
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];    // ends have to match, and so do interiors
            }
        }
        vector<string> curr;
        helper(s, 0, curr);
        return res;
    }
    
    void helper(string& s, int start, vector<string>& curr){
        int N = s.length();
        if(start == N){
            res.push_back(curr);
            return;
        }
        for(int i = start; i != N; ++i){
            if(dp[start][i]){   // s from start to i is a palindrome
                curr.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, curr); // make palindromes with the rest
                curr.pop_back();
            }
        }
    }
};
