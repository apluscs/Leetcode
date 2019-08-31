/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int[] pre, post;
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        this.pre = pre;
        this.post = post;
        return recur(0, 0, pre.length);
    }

    TreeNode recur(int i, int j, int N) { //i,j = start of left and right subtree respectively
        if (N == 0) return null; //
        TreeNode curr = new TreeNode(pre[i]);
        if (N == 1) return curr; //length of pre
        int len = 0;
        for (; len != N; len++)
            if (post[j + len] == pre[i + 1]) break; //pre[i+1] = start of left subtree
        len++;
        curr.left = recur(i + 1, j, len);
        curr.right = recur(i + len + 1, j + len, N - 1 - len);
        return curr;
    }
}
