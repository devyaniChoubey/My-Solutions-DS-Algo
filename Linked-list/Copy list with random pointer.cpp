https://leetcode.com/problems/copy-list-with-random-pointer/description/

https://www.youtube.com/watch?v=VNf6VynfpdM&t=1024s
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;

        Node* temp = head;
        while(temp != NULL){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random =  mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};


optimised

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
     
        Node* cur = head;
        Node* front = head;
        while(cur != NULL){
            front = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = front;
            cur = front;
        }

        cur = head;
        while(cur){
            cur->next->random = cur->random == NULL ? NULL : cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        front = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while(cur != NULL){
            front = cur->next->next;
            dummy->next = cur->next;
            cur->next = front;
            dummy = dummy->next;
            cur = front;
        }

        return res->next;


    }
};