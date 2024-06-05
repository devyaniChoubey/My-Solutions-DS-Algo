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


class BrowserHistory {
public:
    stack<string>history;
    stack<string>future;

    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }
    
    string back(int steps) {
        while(history.size() > 1 && steps > 0){
            future.push(history.top());
            history.pop();
            steps--;
        }

        return history.top();
    }
    
    string forward(int steps) {
        while(!future.empty() && steps > 0){
            history.push(future.top());
            future.pop();
            steps--;
        }

        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */