"""
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Source - https://leetcode.com/problems/validate-binary-search-tree/
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode, maxValue=float('inf'), minValue=-float('inf')) -> bool:
        # If empty tree return true
        if not root:
            return True
        # BST Property Violation Check
        if root.val >= maxValue or root.val <= minValue:
            return False
        # Recur for left and right sub-tree
        return self.checkBST(root.left, root.val, minValue) and self.checkBST(root.right, maxValue, root.val)
