
https://practice.geeksforgeeks.org/problems/burning-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*>parentPointer;
        queue<Node*>q;
        q.push(root);
        Node* targetNode;
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node->data == target) targetNode = node;
            
            if(node->left){
                parentPointer[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                parentPointer[node->right] = node;
                q.push(node->right);
            }
        }
        
        set<Node*>vis;
        q.push(targetNode);
        vis.insert(targetNode);
        int totalTimeTaken = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            int flag = 0;
            for(int i=0;i < size;i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left){
                    if(vis.find(node->left) == vis.end()){
                        q.push(node->left);
                        vis.insert(node->left);
                        flag = 1;
                    }
                }
                
                if(node->right){
                    if(vis.find(node->right) == vis.end()){
                        q.push(node->right);
                        vis.insert(node->right);
                        flag = 1;
                    }
                }
                
                if(parentPointer[node] && vis.find(parentPointer[node]) == vis.end()){
                    q.push(parentPointer[node]);
                    vis.insert(parentPointer[node]);
                    flag = 1;
                }
            }

            if(flag == 1) totalTimeTaken++;
            
        }
        
        return totalTimeTaken;
    }
};