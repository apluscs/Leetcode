class Solution {  
// https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/461528/C%2B%2B-beats-100-in-time-and-space-(0ms)
// BOO YAH ! :D
public:
    vector<int> diffWaysToCompute(string str) {
        int N=str.length(), start=0;
        vector<int> nums; vector<char> ops;   // ops[i] is between nums[i] and nums[i+1]
        for(int i=0;i!=N;i++){
            char op=str[i];
            if(op=='+' || op=='-' || op=='*'){
                nums.push_back(stoi(str.substr(start,i-start)));
                ops.push_back(op);
                start=i+1;
            }
        }   // break up str into an array of just numbers, and another of just ops
        nums.push_back(stoi(str.substr(start)));    // push back last num
        N=nums.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N));
        for(int cy=N;cy!=0;cy--)   // cycle
            for(int i=0;i!=cy;i++){
                int j=i-cy+N;   // go along diagonal (NW to SE)
                if(i==j){ dp[i][j].push_back(nums[i]); continue;   }
                for(int k=i;k!=j;k++)
                    add(dp, ops[k], i, k, j);
            }
        return dp[0][N-1];
    }
    
    void add(vector<vector<vector<int>>> &dp, char op, int i, int k, int j){
        for(int a:dp[i][k]) // for each num possible in LHS
            for(int b:dp[k+1][j])   // traverse RHS as well
                if(op=='+') dp[i][j].push_back(a+b);    // put together the two nums
                else if(op=='-') dp[i][j].push_back(a-b);   // using appropriate op
                else dp[i][j].push_back(a*b);
    }
};

class Solution2 {
    public:
        vector < int > diffWaysToCompute(string str) {
            int N = str.length();
            vector < int > res;
            for (int i = 0; i != N; i++) {
                char op = str[i];
                if (op != '+' && op != '-' && op != '*') continue;
                vector < int > A = diffWaysToCompute(str.substr(0, i)), // break str here
                    B = diffWaysToCompute(str.substr(i + 1)); // 
                for (int a: A)
                    for (int b: B) // try all combinations of two parts
                        if (op == '+') res.push_back(a + b); // using appropriate op
                        else if (op == '-') res.push_back(a - b);
                else res.push_back(a * b);
            }
            if (res.empty()) res.push_back(stoi(str)); // just a number
            return res;
        }
};
