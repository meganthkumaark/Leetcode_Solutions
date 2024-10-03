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
class Solution 
{
    public List<Integer> preorderTraversal(TreeNode root) 
    {
        //expection -> return pre order of the in a list <integer>
        if(root == null)
        {
            return new ArrayList<>();
        }

        //faith -> grt thr pre order of list and return 
        List<Integer> lst = preorderTraversal(root.left);
        List<Integer> rst = preorderTraversal(root.right);

        //create the pre order of actual tree
        List<Integer> ans = new ArrayList<>();

        ans.add(root.val); // first add the node

        //thn add lst
        for(int ele : lst)
        {
            ans.add(ele);
        }

        //then add rst
        for(int ele : rst)
        {
            ans.add(ele);
        }
        
        return ans;
    }
}