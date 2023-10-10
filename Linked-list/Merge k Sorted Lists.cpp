https://leetcode.com/problems/merge-k-sorted-lists/description/
https://leetcode.com/problems/merge-k-sorted-lists/editorial/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        
        priority_queue <ListNode*, vector<ListNode*>, decltype(cmp) > pq(cmp); 

        for(ListNode* node:lists){
            if(node != NULL)pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;

            if(tail->next != NULL) pq.push(tail->next);
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


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            }else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }

        if(l1 != NULL) res->next = l1;

        if(l2 != NULL) res->next = l2;

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;

        while(interval < amount){
            for(int i=0;i < amount-interval;i += interval*2){
               lists[i] = mergeTwoLists(lists[i] , lists[i+interval]); 
            }
            interval *= 2;
        }

        return amount > 0 ? lists[0] : NULL;
    }

};