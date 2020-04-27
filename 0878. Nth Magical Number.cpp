class Solution {  // first one done by myself in a while :)
public:
    const int MOD=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long low=1,high=long(a)*b*n;
        long ab=lcm(a,b);
        while(low<=high){
            long mid=(low+high)/2;
            long count=mid/a+mid/b-mid/ab;
            if(count<n){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return int(low%MOD);
    }
    
    long lcm(long a, long b)  {  
        return (a*b)/__gcd(a, b);  
    } 

};
