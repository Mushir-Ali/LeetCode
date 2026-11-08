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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        priority_queue<pair<int,ListNode*>>pq;
        for(auto i:lists){
            if(i) pq.push({i->val,i});
        }
        while(pq.size()>1){
            ListNode* l1 = pq.top().second;
            pq.pop();
            ListNode* l2 = pq.top().second;
            pq.pop();
            ListNode* l3 = mergeTwoLists(l1,l2);
            pq.push({l3->val,l3});
        }
        if(pq.empty()) return NULL;
        return pq.top().second;
    }
};