https://leetcode.com/problems/design-browser-history/

class DLLNode {
    public:
    string data;
    DLLNode *prev, *next;
    
    DLLNode(string url){
        this->data = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    DLLNode* linkedListHead;
    DLLNode* current;
    BrowserHistory(string homepage) {
        linkedListHead = new DLLNode(homepage);
        current = linkedListHead;
    }
    
    void visit(string url) {
        DLLNode *newNode = new DLLNode(url);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }
    
    string back(int steps) {
        while(steps > 0 && current->prev != NULL){
            current = current->prev;
            steps--;
        }

        return current->data;
    }
    
    string forward(int steps) {
        while(steps > 0 && current->next != NULL){
            current = current->next;
            steps--;
        }

        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */