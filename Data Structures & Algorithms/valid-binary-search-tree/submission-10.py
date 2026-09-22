# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def vbst(self,maxl,minl,root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        if minl>=root.val or maxl<=root.val:
            return False
        return self.vbst(root.val,minl,root.left) and self.vbst(maxl,root.val,root.right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.vbst(1000000000,-1000000000,root)
        