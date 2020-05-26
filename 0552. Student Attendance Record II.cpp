class Solution {
public:
    int mod=1e9+7;
    int checkRecord(int n) {
        vector<vector<long>> curr(2,vector<long>(3)),next(2,vector<long>(3));
        curr[0][0]=1;
        for(int i=0;i!=n;++i){
            // vector<vector<long>> next(2,vector<long>(3));
            int a=accumulate(curr[0].begin(), curr[0].end(),long(0))%mod, b=accumulate(curr[1].begin(), curr[1].end(),long(0))%mod;
            next[0][0]=a;
            next[0][1]=curr[0][0];
            next[0][2]=curr[0][1];
            next[1][0]=(a+b)%mod;
            next[1][1]=curr[1][0];
            next[1][2]=curr[1][1];
            swap(curr,next);
            
        }
        int res=0;
        for(auto v:curr){
            for(auto num:v){
                res=(res+num)%mod;
            }
        }
        return res;
    }
};
