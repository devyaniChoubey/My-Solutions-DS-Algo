/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int>mp;

        while(head != NULL){
            if(mp[head] > 0){
               return head;
            }else{
               mp[head]++;
               head = head->next;
            }
        }

        return NULL;
    }
};








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCyclic = false;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCyclic = true;
                break;
            }
        }
        
        if(!isCyclic) return NULL;
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }

        return slow;
    }
};