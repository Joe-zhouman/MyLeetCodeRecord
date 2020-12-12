class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 72ms, 13.6MB
        [a, b] = self.oneBitSum(l1.val + l2.val)
        sumL = ListNode(a)
        head = ListNode(0)
        head.next = sumL
        l1, l2 = self.nextNode(l1, l2)
        while l1 is not None and l2 is not None:
            [a, b] = self.oneBitSum(l1.val+l2.val+b)
            sumL.next = ListNode(a)
            sumL, l1 = self.nextNode(sumL, l1)
            l2 = l2.next
        if l1 is None:
            sumL.next = l2
        else:
            sumL.next = l1
        if b == 0:
            return head.next
        while sumL.next is not None:
            sumL = sumL.next
            [a, b] = self.oneBitSum(sumL.val+b)
            sumL.val = a
            if b == 0:
                return head.next
        if b != 0:
            sumL.next = ListNode(1)
        return head.next

    def nextNode(self, l1, l2):
        l1 = l1.next
        l2 = l2.next
        return l1, l2

    def oneBitSum(self, s: int):
        a = s % 10
        b = s // 10
        return [a, b]


nodeL11 = ListNode(9)
nodeL12 = ListNode(8)
nodeL11.next = nodeL12
nodeL21 = ListNode(1)

S = Solution().addTwoNumbers(nodeL11, nodeL21)
while S is not None:
    print(S.val)
    S = S.next
