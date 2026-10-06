/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Time Complexity O(n)
        // Space O(1)
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy; // copy groupPrev from dummy
        while (true)
        {
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr)
                break;
            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext; // trick in normal reverse prev will start at nullptr
            ListNode* cur = groupPrev->next;
            // reverse Linked List
            while (cur != groupNext) // trick 2: we must ensure cur != groupNext (reverse sub K group)
            {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = prev;
                prev = tmp;
            }

            // trick force dummyNode get to first reversed Linklist
            ListNode* tmp = groupPrev->next; // dummy->1<-2<-3  4
                                            //                  ^
                                            //         |--------|
                                            // After: dummy->3->2->1->4
            groupPrev->next = kth; // now dummy point to 3 dummy->3
            groupPrev = tmp; // groupPrev = 1, and 4 (this round's groupNext) now follows it
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
private:
    ListNode* getKth(ListNode* cur, int k)
    {
        while (cur && (k!= 0))
        {
            cur = cur->next;
            k--;
        }
        return cur;
    }
};
