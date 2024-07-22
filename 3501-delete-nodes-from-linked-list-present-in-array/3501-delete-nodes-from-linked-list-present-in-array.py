class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        res_cur = res
        cur = head
        num_set = set(nums)
        
        while cur:
            if cur.val not in num_set:
                res_cur.next = ListNode(cur.val)
                res_cur = res_cur.next
            cur = cur.next
        
        return res.next