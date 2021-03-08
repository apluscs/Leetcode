class Solution {
public:
  // state = which group we are, cummulative XOR up to this point;  value = max amount of indices we don't need to change
  int n, k, frq[2001][1024], dp[2001][1024];
  int minChanges(vector<int>& nums, int k) {
    n = nums.size(),this->k = k, memset(frq, 0 ,sizeof(frq)), memset(dp, 0 ,sizeof(dp));
    for(int i=0; i!=k; ++i) {
      for(int j=i; j<n; j+=k) frq[i][nums[j]]++;
    }
    int prev = 0;
    for(int i=0; i!=k; ++i) {
      fill_n(dp[i], 1024, prev);
      for(int j=i; j<n; j+=k) { // which values are relevant
        int val = nums[j];
        for(int u = 0; u != 1024; ++u) {  // u = val ^ ??
          dp[i][u] = max(dp[i][u], !i ? u == val ? frq[i][val] : 0 : frq[i][val] + dp[i-1][u ^ val]); // need cummulate XOR to be == u, so everything before must accumulate to u ^ val
          // if the first group, groups before you cannot achieve any XOR besides '0' so they cannot 'save' you. Thus you can only achieve cumm XOR of u if val == u, in which case max #saved = frq[i][val]
          prev = max(prev, dp[i][u]);
          // printf("i=%d, val=%d, u=%d, dp[i][u]=%d\n", i,val,u, dp[i][u]);
        }
      }
      
    }
    return n - dp[k-1][0];
  }

};
