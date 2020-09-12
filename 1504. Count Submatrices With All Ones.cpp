class Solution {
public:
  int n,m;
  int numSubmat(vector<vector<int>>& mat) {
    n=mat.size(),m=mat[0].size();
    int res=0;
    vector<int> h(m);
    for(int i=0;i!=n;++i){
      vector<int>sum(m); // track continuous columns
      stack<int> st;  // monotonic increasing means: current top is max of the whole stack
      for(int j=0;j!=m;++j){
        h[j]=mat[i][j]?h[j]+1:0;
        while(!st.empty()&&h[st.top()]>=h[j])st.pop();
        if(st.empty()){ // everything left of you is >= you
          sum[j]=h[j]*(j+1);
        }else{  // first one less than you: everything can be extended to you; must also account for everything between st.top() and j, which is taller than h[st.top()]
          sum[j]=sum[st.top()]+(j-st.top())*h[j];
        }
        res+=sum[j];
        // printf("i=%d, j=%d, sum=%d\n",i,j,sum[j]);
        st.push(j);
      }
    }
    return res;
  }
};
