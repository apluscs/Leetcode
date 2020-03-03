void helper(TreeNode* curr, unordered_map<int,int>& sums){    // morris in order traversal
        TreeNode* prev;
        while(curr != nullptr){
            if(curr->left == nullptr){   // just move onto next largest
                process(curr, sums);  // first time visiting curr
                curr = curr->right; 
                continue;
            }
            prev = curr->left;
            while(prev->right != nullptr && prev->right != curr){ // get left's rightmost
                prev = prev->right;
            }
            if(prev->right == nullptr){ // first time visiting curr
                process(curr, sums);
                prev->right = curr;
                curr = curr->left;   // move onto left child of curr
            } else {    // prev's right connects to curr --> we already visited curr and curr's left side
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }   // only difference between this and morris-inorder is that we process curr the first time we visit it, not the first
