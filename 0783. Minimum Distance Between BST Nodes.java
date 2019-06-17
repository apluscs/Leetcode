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
    int prev = -1, res = Integer.MAX_VALUE;
    public int minDiffInBST(TreeNode root) {
        if (root.left != null) minDiffInBST(root.left);
        if (prev != -1) res = Math.min(res, root.val - prev); //always compares with the one just less than current
        prev = root.val; //goes in ascending order from least to greatest
        if (root.right != null) minDiffInBST(root.right);
        return res;
    }
}
