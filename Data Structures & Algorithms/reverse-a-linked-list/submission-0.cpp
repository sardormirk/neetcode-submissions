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
    ListNode* reverseList(ListNode* head) {
        // 0 1 2 3
        // 0->nullptr         temp = 1, prev = 0, 
        // 1->0->nullptr      temp = 2, prev =1
        // 2->1->0->nullptr 
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur)
        {
            ListNode* temp = nullptr;
            if (cur->next)
            {
                temp = cur->next;
            }
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
