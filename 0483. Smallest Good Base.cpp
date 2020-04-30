class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long target=stol(n);
        for(int d=log(target)/log(2)+1;d!=1;--d){  // max #digits when it's base 2
            unsigned long low=2,high=(pow(double(target),1.0/(d-1))+1);  // dth root of target
            // cout<<"low="<<low<<", high="<<high<<endl;
            while(low<=high){
                unsigned long mid=(low+high)/2,sum=0,curr=1;
                for(int i=0;i!=d;++i){
                    sum+=curr;
                    curr*=mid;
                }
                // if(d==2)cout<<"mid="<<mid<<", sum="<<sum<<", d="<<d<<endl;
                if(sum==target) return to_string(mid);
                if(sum<target)low=mid+1;
                else high=mid-1;
            }
        }
        return to_string(target-1); // worst case
    }
};
