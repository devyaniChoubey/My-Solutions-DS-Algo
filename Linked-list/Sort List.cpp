https://leetcode.com/problems/sort-list/

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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* cur = new ListNode(0);
        ListNode* temp = cur;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1) temp->next = l1;
        if(l2) temp->next = l2;

        cur = cur->next;
        

        return cur;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMiddle(head);

        ListNode* firstHead = head;
        ListNode* secondHead = mid->next;

        mid->next = NULL;

        firstHead = sortList(firstHead);
        secondHead = sortList(secondHead);

        return merge(firstHead, secondHead);
    }
};