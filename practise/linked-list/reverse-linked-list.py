"""
Given the head of a singly linked list, reverse the list, and return the reversed list.

Source - https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # Empty list or list with single element
        if (not head) or (head.next == None):
            # Return head node
            return head
        # Current Node
        currNode = head.next
        prevNode = head
        prevNode.next = None
        # Reverse links in the list
        while currNode.next:
            nextNode = currNode.next
            currNode.next = prevNode
            prevNode = currNode
            currNode = nextNode
        # Link last node
        currNode.next = prevNode
        # currNode is head of new linked-list
        return currNode