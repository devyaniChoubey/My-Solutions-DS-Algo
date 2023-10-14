https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int findLinkedListLen(ListNode* head){
    int len = 0;

    while(head != NULL){
        head = head->next;
        len++;
    }

    return len;
}
ListNode* Solution::solve(ListNode* head, int k) {
    int length = findLinkedListLen(head);

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy, *cur = head;
    bool reverse = true;
    

    while(length >= k){
        for(int i=0;i < k-1;i++){
            if(reverse == true){
                ListNode* forw = cur->next;
                cur->next = forw->next;
                forw->next = prev->next;
                prev->next = forw;
            }else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        
        reverse = !reverse;
        prev = cur;
        cur = prev->next;
        length -= k;
    }

    return dummy->next;
}
