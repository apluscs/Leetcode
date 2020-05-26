class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        res[0]=1;
        int diff=k;
        for(int i=1;i!=k+1;++i){
            res[i]=res[i-1]+diff;
            diff=(abs(diff)-1)*(diff<0?1:-1);   // if neg, makke pos
            // cout<<res[i]<<" ";
        }
        if(k+1>=n)return res;
        res[k+1]=k+2;
        for(int i=k+2;i!=n;++i){
            res[i]=res[i-1]+1;
        }
        return res;
    }
};
