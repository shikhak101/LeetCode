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
    public boolean solution_rec(TreeNode curr, double ll, double ul)
    {
        if(curr == null) return true;
        
        if (curr.val >= ul || curr.val <= ll) return false;
        
        return solution_rec(curr.left,ll,curr.val) && solution_rec(curr.right,curr.val,ul);
    }
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        double ll = Double.NEGATIVE_INFINITY;
        double ul = Double.POSITIVE_INFINITY;
        return solution_rec(root,ll,ul);
    }
    
}