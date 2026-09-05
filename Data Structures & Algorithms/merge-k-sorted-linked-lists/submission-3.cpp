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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummyNode;
        ListNode* iterator = &dummyNode;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                iterator->next = l1;
                l1 = l1->next;
            }
            else
            {
                iterator->next = l2;
                l2 = l2->next;
            }
            iterator = iterator->next;
        }
        iterator->next = l1 ? l1 : l2;
        return dummyNode.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.empty()) return nullptr;

        int n = lists.size();
        while (n > 1)
        {
            int i = 0, j = n - 1;
            while (i < j)
            {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++;
                j--;
            }
            n = j + 1;   // number of "active" merged lists remaining
        }
        return lists[0];
    }
};
