void helper(TreeNode* curr){    // morris in order traversal
        TreeNode* prev;
        while(curr != nullptr){
            if(curr->left == nullptr){   // just move onto next largest
                // cout << curr->val << ", ";
                curr = curr->right; 
                continue;
            }
            prev = curr->left;
            while(prev->right != nullptr && prev->right != curr){ // get left's rightmost
                prev = prev->right;
            }
            if(prev->right == nullptr){
                prev->right = curr;
                curr = curr->left;   // move onto left child of curr
            } else {    // prev's right connects to curr --> we already visited everything before curr
                prev->right = nullptr;
                // cout << curr->val << ", ";
                curr = curr->right;
            }
        }
    }
