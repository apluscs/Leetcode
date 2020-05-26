class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // int a=-2,b=2;t\4>(a)<<" "<<bitset<4>(b)<<endl;
        bitset<31>res(INT_MAX),x(m),y(n);
        for(int i=0;i<32;++i){
            if(n-m>(1<<i) || x[i]==0 || y[i]==0)res[i]=0;
        }   // 
        return (int)(res.to_ulong());
    }
};
