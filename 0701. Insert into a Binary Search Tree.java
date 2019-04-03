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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        TreeNode curr = root;
        while (curr != null) {
            // System.out.println(curr.val);
            if (val > curr.val) {
                if (curr.right == null) { //must connect new node to parent.
                    curr.right = new TreeNode(val);
                    break; //no break = endless loop
                }
                curr = curr.right;
            } else {
                if (curr.left == null) {
                    curr.left = new TreeNode(val);
                    break;
                }
                curr = curr.left;
            }
        }
        return root;
    }
}
