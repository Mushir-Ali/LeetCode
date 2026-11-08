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
    
    ListNode* reverse(ListNode* head){
        if (head == NULL || head->next == NULL)return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int val = k - 1;
        ListNode* main = head;
        ListNode* h1 = head;

        while (val && h1->next) {
            h1 = h1->next;
            val--;
        }

        if (val != 0) return head;

        ListNode* h2 = h1->next;
        h1->next = NULL;

        ListNode* newHead = reverse(main);

        main->next = reverseKGroup(h2, k);

        return newHead;
    }
};