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
    bool isPalindrome(ListNode* head) {
      if(head == NULL || head->next == NULL) return true;
      ListNode* slow = head;
      ListNode* fast = head;

      //Code to find middle of the linked list
      while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
      }

      ///Reverse Linked List Code

      ListNode* prev = NULL;
      ListNode* newHead = slow->next;
      while(newHead != NULL){
        ListNode* next = newHead->next;
        newHead->next = prev;
        prev = newHead;
        newHead = next;
      }

      slow->next = prev;

      slow = slow->next;

      //Reverse Linked List Code ends here

      while(slow != NULL){
        if(head->val != slow->val) return false;

        head = head->next;
        slow = slow->next;
      }

      return true;


    }
};