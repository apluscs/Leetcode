class Solution {
public:
    vector<string> board;

    const int MOD=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>dp (n+1, vector<int>(n+1));  // buffer below and right
        vector<vector<long>>count(n+1, vector<long>(n+1));
        // this->board=board;
        count[n][n]=1;
        for(int i = n-1; i != -1; --i){ // dp[i][j]=max score possible at i,j
            for(int j =n-1; j != -1; --j){
                if(board[i][j]=='X' || !good(i,j,board)) continue;  // must be 0
                int curr=board[i][j]-'0';
                if(curr>10)curr=0;  
                int a=dp[i+1][j+1], b=dp[i+1][j], c=dp[i][j+1],m=max(a,max(b,c));
                dp[i][j]= m+curr;
                if(m==a) count[i][j]+= count[i+1][j+1];
                if(m==b) count[i][j]+= count[i+1][j];
                if(m==c) count[i][j]+= count[i][j+1];
                if(count[i][j]==0) dp[i][j]=0;
                count[i][j]%=MOD;
                dp[i][j]%=MOD;
                // cout<<dp[i][j]<<"----"<<count[i][j]<<","<<board[i][j]<<endl;
            }
            // cout<<endl;
        }
        vector<int>res={dp[0][0],int(count[0][0])};
        return res;
    }

    bool good(int i,int j,vector<string>& board){
        int n=board.size();
        if(i==n-1 && j==n-1) return true;
        bool a=(i!=n-1 && j!=n-1 && board[i+1][j+1]!='X');  // down right is a go
        bool b=(i!=n-1 && board[i+1][j]!='X');  // down is a go
        bool c=(j!=n-1 && board[i][j+1]!='X');  // right is a go
        // cout<<i<<", "<<j<<","<<a<<", "<<b<<", "<<c<<endl;
        return a || b || c;
    }
};
