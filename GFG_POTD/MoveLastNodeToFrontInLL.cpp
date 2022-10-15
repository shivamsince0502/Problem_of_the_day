class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head->next == NULL) return head;
        ListNode* first = head;
        while(head->next->next != NULL) {
            head = head->next;
        }
        head->next->next = first;
        first = head->next;
        head->next = NULL;
        return first;
    }
};
