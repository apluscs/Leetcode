class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();   
        vector<vector<int>> prefix(n,vector<int>(m)), res(n,vector<int>(m));
        for(int i=0;i!=n;++i){
            for(int j=0;j!=m;++j){
                prefix[i][j]=mat[i][j]+ (i==0?0:prefix[i-1][j]) + (j==0?0:prefix[i][j-1]) - ((i==0||j==0)?0:prefix[i-1][j-1]);
                // cout<<prefix[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=0;i!=n;++i){
            for(int j=0;j!=m;++j){
                res[i][j]=get(prefix,i+k,j+k)-get(prefix,i-k-1,j+k) -get(prefix,i+k,j-k-1) + get(prefix,i-k-1,j-k-1);
            }
            // cout<<endl;
        }
        return res;
    }
    
    int get(vector<vector<int>>& mat, int i,int j){
        int n=mat.size(),m=mat[0].size();
        if(i<0||j<0)return 0;
        i=min(i,n-1);
        j=min(j,m-1);
        return mat[i][j];
    }
};
