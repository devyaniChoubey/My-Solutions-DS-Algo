https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* dummy = head;

    while(dummy != NULL){
        if(dummy->next){
            if(dummy->next->val == dummy->val){
                dummy->next = dummy->next->next;
                continue;
            }
        }
        dummy = dummy->next;
    }

    return head;
}
