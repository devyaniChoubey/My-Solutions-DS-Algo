https://www.interviewbit.com/problems/even-reverse/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 


ListNode* Solution::solve(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* prev = NULL, *cur = head, *next = NULL;
    
    while(cur && cur->next){
        next = cur->next;
        cur->next = next->next;
        next->next = prev;
        
        prev = next;
        cur = cur->next;
    }
    
    cur = head;
    
    while(cur && prev){
        next = cur->next;
        cur->next = prev;
        prev = prev->next;
        cur->next->next = next;
        
        
        cur = cur->next->next;
    }
    
    return head;
    
}




