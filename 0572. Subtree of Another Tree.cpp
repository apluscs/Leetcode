/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool mid = isEqual(s, t);
        if(s == nullptr) return false;  // because t is not a nullptr
        return mid || isSubtree(s->left, t) || isSubtree(s->right, t);  // try all possible subtrees
    }
    
    bool isEqual(TreeNode* whole, TreeNode* part){  // part is not a nullptr
        if(part == nullptr && whole == nullptr) return true;
        if(part == nullptr || whole == nullptr) return false;   // only one is null
        return whole->val == part->val && isEqual(whole->left, part->left) && isEqual(whole->right, part->right);   // roots must be equal; left and right parts must be equal
    }
};
