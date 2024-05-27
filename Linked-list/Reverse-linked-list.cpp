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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = newHead;

            newHead = head;
            head = next;
        }

        return newHead;
    }
};


//Recursive

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
    ListNode* solve(ListNode* head, ListNode* prev){
        if(head == NULL) return prev;

        ListNode* next = head->next;
        head->next = prev;

        return solve(next, head);
    }
    ListNode* reverseList(ListNode* head) {
        return solve(head, NULL);
    }
};