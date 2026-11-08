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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* main = l2;
        ListNode* curr = l2;
        ListNode* prev = NULL;
        while(l1){
            while(curr and l1 and curr->val<=l1->val){
                prev = curr;
                curr = curr->next;
            }
            if(curr){
                if (prev == NULL) {
                    ListNode* temp = l1->next;
                    l1->next = curr;
                    main = l1;
                    prev = l1;
                    l1 = temp;
                }
                else {
                    prev->next = l1;
                    ListNode* temp = l1->next;
                    l1->next = curr;
                    prev = l1;
                    l1 = temp;
                }
            }
            else{
                prev->next = l1;
                break;
            }
        }
        return main;
    }
};