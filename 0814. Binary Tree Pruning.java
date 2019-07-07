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

    public TreeNode pruneTree(TreeNode root) {
        TreeNode rroot = new TreeNode(-1);
        rroot.left = root;
        helper(rroot);
        return rroot.left; //since we can only prune from parent, we need to add a node higher than root
    }
    boolean helper(TreeNode curr) {
        if (curr == null) return false;
        boolean l = helper(curr.left);
        boolean r = helper(curr.right);
        if (!l) curr.left = null; //must prune nodes from the parent
        if (!r) curr.right = null;
        return curr.val == 1 || r || l;
        // System.out.println(curr.val + " "+l+" "+r);
    }
}
