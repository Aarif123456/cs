from queue import PriorityQueue

def mergeKLists(streams):
    count = 0 # bypass python no duplicate issue
    sorted_list = []

    pq = PriorityQueue()
    for cur_list in streams:
        if len(cur_list)>0:
            count += 1
            pq.put_nowait((cur_list[0], count, cur_list))

    while not pq.empty():
        (_,_, cur_list) = pq.get_nowait()
        ele = cur_list.pop(0)
        sorted_list.append(ele)
        if len(cur_list) > 0: 
            count += 1
            pq.put_nowait((cur_list[0], count, cur_list))

    return sorted_list

import unittest

class mergeTest(unittest.TestCase):

    def test_function(self):
        test_cases = \
            [
               ([[1,4,5],[1,3,4],[2,6]], [1,1,2,3,4,4,5,6]),\
               ([],[]),\
               ([[]],[]),\
               ([[1],[0]], [0,1]),\
               ([[],[1]], [1])
            ]

        for arguments, expected in test_cases:
            with self.subTest(arguments=arguments, expected=expected):
                self.assertEqual(mergeKLists(arguments), expected)


if __name__ == '__main__':
    unittest.main()
















# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, streams: List[ListNode]) -> ListNode:
        count = 0 # bypass python no duplicate issue
        dummy = ListNode(None)
        cur = dummy

        pq = PriorityQueue()

        for cur_list in streams:
            count += 1
            if cur_list: pq.put_nowait((cur_list.val, count, cur_list))

        while not pq.empty():
            (_, _, cur_list) = pq.get_nowait()
            cur.next = cur_list
            cur = cur_list
            if cur_list.next is not None: 
                count += 1
                pq.put_nowait((cur_list.next.val, count, cur_list.next))

        return dummy.next