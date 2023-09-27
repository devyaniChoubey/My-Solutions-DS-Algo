https://leetcode.com/problems/clone-graph/description/

//BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;

        unordered_map<Node*, Node*>visited;

        queue<Node*>q;
        q.push(node);
        visited[node] = new Node(node->val, {});

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(auto adjNode:cur->neighbors){
                if(visited.find(adjNode) == visited.end()){
                    q.push(adjNode);
                    visited[adjNode] = new Node(adjNode->val, {});
                }
                visited[cur]->neighbors.push_back(visited[adjNode]);
            }
        }

        return visited[node];
    }
};


//DFS


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>visited;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        
        if(visited.find(node) != visited.end()){
            return visited[node];
        }

        Node* clonedNode = new Node(node->val, {});

        visited[node] = clonedNode;

        for(auto adjNode:node->neighbors){
            clonedNode->neighbors.push_back(cloneGraph(adjNode));
        }

        return clonedNode;
    }
};