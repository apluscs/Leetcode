class Solution {
public:
    int uniquePaths(int M, int N) {
        if(N>M){
            int temp=N; N=M;    M=temp;
        }
        vector<int> curr(M,1);
        vector<int> next(M); 
        for(int i=1;i!=N;i++){
               
            next[i]=curr[i]<<1;
            for(int j=i+1;j!=M;j++){
                // cout<<"hi";
                next[j]=curr[j]+next[j-1];
                // cout<<next[j]<<" ";
            }
            // cout<<"bye";
            curr=next;
            // cout<<endl;
        }
        return curr[M-1];
    }
};
