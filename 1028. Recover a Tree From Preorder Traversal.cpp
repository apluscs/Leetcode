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
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<TreeNode*,int>> st;
        int i=0,n=s.length();
        while(i!=n){
            int temp=0;
            while(s[i]=='-'){
                temp++;
                i++;
            }
            // cout<<i<<" is i"<<endl;
            while(!st.empty()&&temp<st.top().second)
                merge(st,temp);
            int j=i;    // start of integer
            while(i!=n&&isdigit(s[i]))i++;
            int val=stoi(s.substr(j,i-j));
            st.push(make_pair(new TreeNode(val),temp));
            // cout<<val<<", depth="<<temp<<endl;
        }
        while(st.size()>1)merge(st,0);
        return st.top().first;
    }

    void merge(stack<pair<TreeNode*,int>>& st,int temp){
        TreeNode* a=st.top().first,* b=nullptr;    // node at a lower level than you
        int k=st.top().second;
        st.pop();
        // cout<<"popped off "<<a->val<<endl;
        if(st.top().second==k){   // another one(siblings)
            b=st.top().first; st.pop();
            // cout<<"popped off "<<b->val<<endl;
        }
        st.top().first->left=b?b:a;
        if(b)st.top().first->right=a;
    }
};







