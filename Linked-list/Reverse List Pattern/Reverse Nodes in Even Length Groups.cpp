https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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
    int countNodes(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int totalNodes = countNodes(head);

        int numOfNodes = 1;
        ListNode* dummy = new ListNode(0, head), *cur = head;
        ListNode* prev = dummy;

        while(cur != NULL){
            numOfNodes = min(numOfNodes, totalNodes);
            totalNodes -= numOfNodes;

            if(numOfNodes % 2 == 1){
                int cnt = 0;

                while(cur && cnt < numOfNodes){
                    prev = prev->next;
                    cur = cur->next;
                    cnt++;
                }
            }else{
                
                for(int i=0;i < numOfNodes-1;i++){
                    ListNode* forw = cur->next;
                    cur->next = forw->next;
                    forw->next = prev->next;
                    prev->next = forw;
                }

                prev = cur;
                cur = prev->next;
            }

            numOfNodes++;
        }

        return dummy->next;
    }
};