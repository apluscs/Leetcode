/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root, bool leftmost = true) {
        if(root == nullptr) return root;
        Node* nnext = root->next;   // will end up as leftmost node right of root
        while(nnext){   // keep going next until you find smthg that has at least 1 kid
            if(nnext->left){
                nnext = nnext->left;
                break;
            }
            if(nnext->right){
                nnext = nnext->right;
                break;
            }
            nnext = nnext->next;
        }

        if(root->left)
            root->left->next = root->right ? root->right : nnext;
        if(root->right)
            root->right->next = nnext;
        
        connect(root->next, false); // go all the way across first, finish this level
        if(leftmost){   // find the leftmost node on the level below
            if(root->left) connect(root->left, true);
            else if(root->right) connect(root->right, true);
            else connect(nnext, true);
        }
        return root;
    }
};
