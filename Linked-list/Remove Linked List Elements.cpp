https://leetcode.com/problems/remove-linked-list-elements/description/

https://leetcode.com/problems/remove-linked-list-elements/editorial/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = head;

        while(dummy != NULL){
            if(dummy->next != NULL && dummy->next->val == val){
                dummy->next = dummy->next->next;
            }else dummy = dummy->next;

        }
        
        if(head != NULL && head->val == val) return head->next;
        return head;
    }
};


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy , *cur = head , *delNode = NULL;

        while(cur != NULL){
            if(cur->val == val){
                prev->next = cur->next;
                delNode = cur;
            }else prev = prev->next;
            cur = cur->next;

            if(delNode != NULL){
                delete delNode;
                delNode = NULL;
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};