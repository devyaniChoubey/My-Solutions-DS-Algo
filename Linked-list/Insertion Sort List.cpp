https://leetcode.com/problems/insertion-sort-list/description/

ListNode* Solution::insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = head;

        while(cur != NULL){
            ListNode* prev = dummy;

            while(prev->next != NULL && prev->next->val <= cur->val){
                prev = prev->next;
            }

            ListNode* next = cur->next;
            
            cur->next = prev->next;
            prev->next = cur;
            
            cur = next;
        }

        return dummy->next;
}
