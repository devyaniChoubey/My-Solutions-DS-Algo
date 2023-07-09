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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = head;
        int cnt = 0;
        while(newHead != NULL){
            newHead = newHead->next;
            cnt++;
        }
        
        if(cnt == 1 || (n - cnt == 0)) {
            head = head->next;
            return head;
        }
   
        ListNode* ans = head;
        for(int i=0;i < (cnt - n - 1);i++){
           head = head->next;
        }
        head->next = head->next->next;
        return ans;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        //if(n == 1) return head->next;

        for(int i=1;i <= n;i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return start->next;
    }
};