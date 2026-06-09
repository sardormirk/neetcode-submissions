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

        /*
        2 -> 4 -> 6 -> 8

        s1       s2
        2 -> 4 | 8 -> 6
                  |
        2 -> 4 -> 6 -> 8 -> 10
        2->4->6 10->8

        2->10->4->8->6
        s1->next = s2;
        s2->next = s1->next;



        2 -> 8

        4 -> 6

        8 -> 4

        2 -> 8 -> 4 -> 6

        get middle of linked list, reverse second half
        iterate and update next pointers

        */
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *s1 = head;
        ListNode *s2 = reverse(slow->next);
        slow->next = nullptr;
        
        while (s2)
        {
            ListNode* temp = s1->next, *temp2 = s2->next;
            s1->next = s2;
            s2->next = temp;
            s1 = temp;
            s2 = temp2;
        }
    }

    ListNode* reverse (ListNode* head)
    {
        ListNode *cur = head, *prev = nullptr;
        while (cur) 
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
