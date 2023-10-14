https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* res = new ListNode(0, head);
        ListNode* prevNode = res, *curNode = head;

        while(curNode != NULL && curNode->next != NULL){
            prevNode->next = curNode->next;
            curNode->next = prevNode->next->next;
            prevNode->next->next = curNode;

            prevNode = curNode;
            curNode = prevNode->next;
        }

        return res->next;
    }
};