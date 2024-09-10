https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/submissions/1340438265/?envType=company&envId=google&favoriteSlug=google-thirty-days&status=TO_DO&difficulty=MEDIUM

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>seen(nums.begin() , nums.end());

        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        
        while(head != NULL){
            if(seen.find(head->val) == seen.end()){
                ans->next = new ListNode(head->val);
                ans = ans->next;
            }
            head = head->next;
        }

        return res->next;
    }
};

//Method 2 

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>seen(nums.begin() , nums.end());

        ListNode* temp = new ListNode(0, head);
        ListNode* ans = temp;

        while(temp->next != NULL){
            if(seen.count(temp->next->val)){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }

        return ans->next;

    }
};