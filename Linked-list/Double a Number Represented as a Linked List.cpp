https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

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
    ListNode* reverseList(ListNode* cur){
        ListNode* prev = NULL;

        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next; 
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
    
        head = reverseList(head);

        int carry = 0;

        ListNode* cur = head;

        while(cur != NULL){
            cur->val += cur->val + carry;
            if(cur->val > 9) carry = 1;
            else carry = 0;

            cur->val = cur->val%10;
            if(cur->next == NULL) break;
            cur = cur->next;
        }

        if(carry == 1) cur->next = new ListNode(carry);

        head = reverseList(head);

        return head;
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

    ListNode* doubleIt(ListNode* head) {
    
        stack<int>st;

        while(head != NULL){
            st.push(head->val);
            head = head->next;
        }

        int carry = 0;

        ListNode* cur = NULL;

        while(!st.empty() || carry == 1){
            int val = 0;

            cur = new ListNode(0, cur);

            if(!st.empty()){
                val = st.top();
                st.pop();
            }

            val += val + carry;

            carry = val/10;

            val = val%10;

            cur->val = val;
        }

        

        return cur;
    }
};


