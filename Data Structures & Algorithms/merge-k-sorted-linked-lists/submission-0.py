# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        outNode = None
        outList = None
        while lists:
            x, next_node = min(enumerate(lists), key=lambda x: x[1].val if x else None)
            lists[x] = next_node.next
            next_node.next = None
            if outList is None:
                outList = next_node
                outNode = next_node
            else:
                outNode.next = next_node
                outNode = next_node
            for i in reversed([x for x, l in enumerate(lists) if not l]):
                lists.pop(i)
        return outList