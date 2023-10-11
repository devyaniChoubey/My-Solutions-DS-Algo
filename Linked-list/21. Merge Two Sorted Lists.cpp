/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* res = new ListNode(0);
    ListNode* dummy = res;
    
    while(A != NULL && B != NULL){
        if(A->val <= B->val){
            dummy->next = A;
            A = A->next;
        }else{
            dummy->next = B;
            B = B->next;
        }
        
        dummy = dummy->next;
    }
    
    if(A != NULL){
        dummy->next = A;
    }
    
    if(B != NULL){
        dummy->next = B;
    }
    
    return res->next;
}



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l2->val < l1->val) swap(l1,l2);

        ListNode* ans = l1;
        while(l1 != NULL && l2 != NULL){
            if(l2->val < l1->val) swap(l1, l2);
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            if(temp != NULL)temp->next = l2;
        }
        return ans;
    }
};