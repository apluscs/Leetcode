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

class SolutionNonRecur {    //non recursive, slower but better memory
    public int minDiffInBST(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        int res=Integer.MAX_VALUE, prev=-1;
        TreeNode curr=root;
        while(curr!=null||!stack.isEmpty()){
            while(curr!=null){
                stack.push(curr);   curr=curr.left;
            }
            curr=stack.pop();
            // System.out.println(curr.val);
            if(prev!=-1)res=Math.min(res,curr.val-prev);
            prev=curr.val;
            curr=curr.right;
        }
        return res;
    }
}
