https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int nodeCnt = 0;

        ListNode* temp = head;

        while(temp != NULL){
            nodeCnt++;
            temp = temp->next;
        }

        int mod = nodeCnt%k;
        int len = nodeCnt/k;

        temp = head;

        vector<ListNode*>ans(k);

        int j = 0;

        for(int i=0;i < k;i++){
            int curLen = len;
            if(i < mod) curLen++;
            ListNode* p = temp;
            ListNode* q = p;
            
            for(int z=0;z < curLen;z++){
                temp = temp->next;
                if(z == curLen-1) p->next = NULL;
                p = p->next;
            }
            ans[j++] = q;
        }

        return ans;
    }
};