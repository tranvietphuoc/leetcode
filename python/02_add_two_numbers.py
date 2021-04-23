

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # just math
        num = 0
        head = ListNode()
        current = head
        while l1 or l2 or num:
            # calculate the sum of each corresponding element of two list
            if l1:
                num += l1.val
                l1 = l1.next  # move to the next element of l1
            if l2:
                num += l2.val
                l2 = l2.next  # move to the next element of l1
            # link to new node
            current.next = ListNode(
                num % 10
            )  # retain the modulo of num with 10 and add to new node
            current = current.next
            num = num // 10  # reset num to the quotient

        return head.next


#         # pythonic
#         num1 = []
#         num2 = []
#         result = ListNode()
#         while l1:
#             num1.append(str(l1.val))
#             l1 = l1.next

#         while l2:
#             num2.append(str(l2.val))
#             l2 = l2.next
#         # adding
#         total = int(''.join(num1[::-1])) + int(''.join(num2[::-1]))
#         str_total = str(total)
#         for val in str_total:

#             tmp = ListNode(int(val))
#             tmp.next = result.next
#             result.next = tmp
#         return result.next
