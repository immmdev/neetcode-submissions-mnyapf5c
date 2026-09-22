# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans=list()
        queue=deque()
        queue.append(root)
        while len(queue)>0:
            l=len(queue)
            sublist=list()
            for i in range(l):
                node=queue.popleft()
                sublist.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                
            ans.append(sublist)
        return ans
                    
                

        