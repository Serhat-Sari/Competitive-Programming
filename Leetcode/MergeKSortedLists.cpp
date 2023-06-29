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
    struct compare {
        bool operator()(const ListNode* l , const ListNode* r){
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,compare > pq;

        for(auto l : lists)
            if(l) pq.push(l);


        if(pq.empty()) return NULL;
        ListNode* head = pq.top();
        pq.pop();
        if(head->next) pq.push(head->next);
        ListNode* tail = head;

        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail ->  next;
            if(tail->next) pq.push(tail->next);
        }

        return head;
    }
};