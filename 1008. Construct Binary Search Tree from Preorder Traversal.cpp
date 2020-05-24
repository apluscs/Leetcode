/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> po,x;
    int n;
    TreeNode* bstFromPreorder(vector<int>& po) {
        this->po=po;
        n=po.size();
        x.resize(n,n);
        stack<int> st;
        for(int i=0;i!=n;++i){  // makes runtime O(N) instead of O(NlogN)
            while(!st.empty()&&po[st.top()]<po[i]){
                x[st.top()]=i;  // x[i]=index of number to the right of you that is greater than yourself
                st.pop();
            }
            st.push(i);
        }
        // for(int i=0;i!=n;++i){
        //     cout<<x[i]<<" ";
        // }
        return solve(0,n-1);
    }
    
    TreeNode* solve(int s,int e){
        if(s>e)return nullptr;
        // cout<<s<<","<<e<<endl;
        // if(s==e) return new TreeNode(po[s]);
        TreeNode* res=new TreeNode(po[s]);
        int i=x[s];
        res->left=solve(s+1,i-1);
        res->right=solve(i,e);
        return res;
    }
};
