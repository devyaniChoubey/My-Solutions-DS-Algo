https://leetcode.com/problems/partition-list/description/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* point1 = new ListNode(0);
        ListNode* point2 = new ListNode(0);
        ListNode* node1 = point1;
        ListNode* node2 = point2;

        while(head != NULL){
            if(head->val < x){
               point1->next = head;
               point1 = point1->next;
            }else{
               point2->next = head;
               point2 = point2->next;
            }

            head = head->next;
        }
        
        point2->next = NULL;
        point1->next = node2->next;

        return node1->next;

    }
};