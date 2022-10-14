// single pointer
ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* itr = head;
        while(itr != NULL) {
            n++;
            itr = itr->next;
        }
        if(n == 1) head = NULL;
        n /= 2;
        itr = head;
        while(n > 0) {
            n--;
            if(n == 0)
                itr->next = itr->next->next;
            itr = itr->next;
        }
        return head;
		
		//two pointers
		ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL) {
            if(fast->next->next == NULL || fast->next->next->next == NULL) {
                slow->next = slow->next->next;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return head;
    }
