https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp){
            int newVal;
            if(temp->next != NULL){
               newVal = __gcd(temp->val, temp->next->val);
               ListNode* next = temp->next;
               temp->next = new ListNode(newVal);
               temp = temp->next;
               temp->next = next;
            }
            temp = temp->next;
        }

        return head;
    }
};