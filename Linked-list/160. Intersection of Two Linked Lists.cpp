//Brute Force


https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != NULL){
            ListNode* temp = headB;
            while(temp != NULL){
                if(temp == headA){
                    return headA;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};



//Using a hash map


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int>mp;
        while(headA != NULL){
            mp[headA]++;
            headA = headA->next;
        }

        while(headB != NULL){
            if(mp[headB] > 0) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* dummyA = headA;
       ListNode* dummyB = headB;
       int lenA = 0, lenB = 0;
       while(dummyA != NULL || dummyB != NULL){
            if(dummyA){
               lenA++;
               dummyA = dummyA->next;
            }
            if(dummyB){
               lenB++;
               dummyB = dummyB->next;
            }
       }
       
        if(lenA > lenB){
           for(int i=0;i < (lenA - lenB);i++){
               headA = headA->next;
           }
        }else{
           for(int i=0;i < (lenB - lenA);i++){
               headB = headB->next;
           } 
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};