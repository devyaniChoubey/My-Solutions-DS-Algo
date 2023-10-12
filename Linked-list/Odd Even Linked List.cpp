https://leetcode.com/problems/odd-even-linked-list/description/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* even = head->next , *odd = head;
        ListNode* evenHead = even;


        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};