https://www.interviewbit.com/problems/kth-node-from-middle/

int Solution::solve(ListNode* head, int B) {
    ListNode* slow = head, *fast = head;
    
    int cnt = 0;
    
    while(fast != NULL && fast->next != NULL){
        cnt++;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cnt = cnt - B;
    
    if(cnt < 0) return -1;
    
    while(cnt != 0){
        head = head->next;
        cnt--;
    }
    
    return head->val;
}
