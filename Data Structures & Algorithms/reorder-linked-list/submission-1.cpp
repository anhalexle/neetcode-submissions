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
    void reorderList(ListNode* head) {
        // vector<int> tempArr;
        // ListNode* cur = head;
        // while(head)
        // {
        //     tempArr.push_back(head->val);
        //     head = head->next;
        // }

        // int l = 0, r = tempArr.size() - 1;
        // bool takeRight = false;
        // while (l <= r)
        // {
        //     if (!takeRight)
        //     {
        //         cur->val = tempArr[l++];
        //     }
        //     else
        //     {
        //         cur->val = tempArr[r--];
        //     }
        //     takeRight = !takeRight;
        //     cur = cur->next;
        // }
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;
        // Detect the half of the linked list
        while(fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        ListNode* secondLinkedList = slowptr->next;
        ListNode* prev = nullptr;
        slowptr->next = nullptr; // split to two Linked list
        
        // reverse second link list
        while(secondLinkedList)
        {
            ListNode* next = secondLinkedList->next;
            secondLinkedList->next = prev;
            prev = secondLinkedList;
            secondLinkedList = next;
        }

        // Merge two linked list
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2)
        {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
