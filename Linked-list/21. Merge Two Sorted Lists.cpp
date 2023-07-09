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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                ListNode* new_node =  new ListNode();
                new_node->val = list1->val;
                dummy->next = new_node;
                dummy = dummy->next;
                list1 = list1->next;
            }else{
                ListNode* new_node =  new ListNode();
                new_node->val = list2->val;
                dummy->next = new_node;
                dummy = dummy->next;
                list2 = list2->next;                                                         
            }
        }


        if(list1 != NULL) {
            dummy->next = list1;
        }

        if(list2 != NULL) {
            dummy->next = list2;
        }

        return ans->next;
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l2->val < l1->val) swap(l1,l2);

        ListNode* ans = l1;
        while(l1 != NULL && l2 != NULL){
            if(l2->val < l1->val) swap(l1, l2);
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            if(temp != NULL)temp->next = l2;
        }
        return ans;
    }
};