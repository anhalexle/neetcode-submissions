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
        vector<int> tempArr;
        ListNode* cur = head;
        while(head)
        {
            tempArr.push_back(head->val);
            head = head->next;
        }

        int l = 0, r = tempArr.size() - 1;
        bool takeRight = false;
        while (l <= r)
        {
            if (!takeRight)
            {
                cur->val = tempArr[l++];
            }
            else
            {
                cur->val = tempArr[r--];
            }
            takeRight = !takeRight;
            cur = cur->next;
        }
    }
};
