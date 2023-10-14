https://www.interviewbit.com/problems/sort-binary-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) {
    ListNode* zeroHead = new ListNode(0), *oneHead = new ListNode(0);
    ListNode* zeroCur = zeroHead, *oneCur = oneHead;
    
    while(head != NULL){
        if(head->val == 0){
            zeroCur->next = head;
            zeroCur = zeroCur->next;
        }else{
            oneCur->next = head;
            oneCur = oneCur->next;
        }
        head = head->next;
    }
    
    oneCur->next = NULL;
    zeroCur->next = oneHead->next;
    return zeroHead->next;
    
}
