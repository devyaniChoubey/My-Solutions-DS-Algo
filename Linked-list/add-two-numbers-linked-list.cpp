https://leetcode.com/problems/add-two-numbers/description/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummy = new ListNode();
       ListNode * res = dummy;
       int carry = 0;
       while(l1 != NULL || l2 != NULL || carry == 1){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            sum = sum%10;
            ListNode * new_node = new ListNode(sum);
            dummy->next = new_node;
            dummy = dummy->next;
       }
       return res->next;
    }
};