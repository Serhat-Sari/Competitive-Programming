class Solution {
public:
    
    bool hasCycle(ListNode *head){
        if(head == NULL)
            return false;
        ListNode *first = head;
        ListNode *second = head;
        while(first != NULL && first->next != NULL){
            first = first->next->next;
            second = second->next;
            if(first == second)
                return true;
        }
        return false;
    }
};