# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.sum = 0
        self.bstToGstHelper(root)
        return root
    
    def bstToGstHelper(self, node: TreeNode):
        if node is None:
            return
        
        self.bstToGstHelper(node.right)
        
        self.sum += node.val
        node.val = self.sum
        
        self.bstToGstHelper(node.left)
