class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n=prices.size(),best=-prices[0];
        vector<int> one(n),two(n);
        for(int i=1;i!=n;++i){
            int curr=prices[i]+best;    // best = best purchase before day i
            one[i]=max(one[i-1],curr);
            best=max(best,-prices[i]);
            // cout<<one[i]<<" ";
        }
        // cout<<endl;
        best= -prices[0];   // best = best (purchase + profit before day i)
        for(int i=1;i!=n;++i){
            int curr=prices[i]+best;    // best = best purchase before day i
            two[i]=max(two[i-1],curr);
            best=max(best,one[i-1]-prices[i]);
            // cout<<two[i]<<" ";
        }
        return two[n-1];
    }
};
