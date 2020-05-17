class Solution {
public:
    int findMaxForm(vector<string>& ss, int m, int n) {
        vector<vector<int>> curr(n+1,vector<int>(m+1));
        for(int k=ss.size()-1;k!=-1;--k){
            int a=count(ss[k],'1'),b=count(ss[k],'0');
            auto next=curr;
            for(int i=0;i!=n+1;++i){    // could save time by going from bottom right to top left
                for(int j=0;j!=m+1;++j){
                    if(a>i||b>j)continue;
                    next[i][j]=max(curr[i-a][j-b]+1,next[i][j]);
                    // cout<<i<<","<<j<<", "<<next[i][j]<<endl;
                }
            }
            curr=next;
            // cout<<endl;
        }
        return curr.back().back();
    }
    int count(string& s,char x){
        int res=0;
        for(char c:s)res+=c==x;
        return res;
    }
};
