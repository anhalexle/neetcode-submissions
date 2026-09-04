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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Set up L, R pointer
        ListNode* left = head;
        int temp = n;
        ListNode* right = head;
        while (temp != 0)
        {
            right = right->next;
            --temp;
        }
        // Shift left and right pointer until right is null, at that time, left ptr will be the ptr need to be removed
        ListNode* prev = nullptr; //use this prev to store previous pointer
        while(right)
        {
            prev = left;
            left = left->next;
            right = right->next;
        }
        if (prev)
        {
            prev->next = left->next;
        }
        else
        {
            head = left->next;
        }
        return head;
    }
};
