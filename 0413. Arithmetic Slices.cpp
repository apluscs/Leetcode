class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size(),res=0;
        for(int i=0;i<n-2;){
            int j=i;
            while(j+2<n &&A[j+2]-A[j+1]==A[j+1]-A[j]){
                j++;
            }
            int len=j+2-i;
            res+=(len-1)*(len-2)/2;
            i=j+1;
        }
        return res;
    }
};
