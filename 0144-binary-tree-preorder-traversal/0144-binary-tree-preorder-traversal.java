/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        //create a bag
        List<Integer> bag = new ArrayList<>();
        fun(root,bag);
        return bag;
    }

    public void fun(TreeNode root, List<Integer> bag){
        //base case
        if(root == null){
            return ;
        }

        //first add the root
        bag.add(root.val);
         
         //pass the bag to lst
         fun(root.left,bag);

         // once done now pass the bag to rst
         fun(root.right,bag);
    }
}