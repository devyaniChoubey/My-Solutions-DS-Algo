https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    int findLinkedListLen(ListNode* head){
        int len = 0;

        while(head != NULL){
            head = head->next;
            len++;
        }

        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = findLinkedListLen(head);

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy, *cur = head;
        

        while(length >= k){
            for(int i=0;i < k-1;i++){
                ListNode* forw = cur->next;
                cur->next = forw->next;
                forw->next = prev->next;
                prev->next = forw;
            }
            
            prev = cur;
            cur = prev->next;
            length -= k;
        }

        return dummy->next;
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
    ListNode* reverseLinkedList(ListNode* head,int k){
        ListNode* newHead = NULL;

        while(k != 0){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
            k--;
        }

        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ktail = NULL;
        ListNode* newHead = NULL;
        ListNode* cur = head;
        int count = 0;

        while(cur){
            count = 0;

            while(count < k && cur != NULL){
                cur = cur->next;
                count++;
            }

            if(count != k) {
                ktail->next = head;
                break;
            }

            ListNode* reverseHead = reverseLinkedList(head,k);
            if(newHead == NULL) newHead = reverseHead;
            if(ktail != NULL) ktail->next = reverseHead;
            ktail = head;
            head = cur;
        }
        return newHead;
    }
};