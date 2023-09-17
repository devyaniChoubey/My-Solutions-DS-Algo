https://leetcode.com/problems/construct-quad-tree/description/
https://leetcode.com/problems/construct-quad-tree/editorial/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool hasSameValue(int r, int c, int length, vector<vector<int>>& grid){
        for(int i=r;i < r+length;i++){
            for(int j=c;j < c+length;j++){
                if(grid[i][j] != grid[r][c]) return false;
            }
        }
        return true;
    }
    Node* constructTree(int r,int c, int length, vector<vector<int>>& grid){
        if(hasSameValue(r, c, length, grid)){
           return new Node(grid[r][c], true);
        }else{
           Node* node = new Node(0, false);

           node->topLeft = constructTree(r, c, length/2, grid);
           node->topRight = constructTree(r, c+(length/2), length/2, grid);
           node->bottomLeft = constructTree(r+(length/2), c, length/2, grid);
           node->bottomRight = constructTree(r+(length/2), c+(length/2), length/2, grid);

           return node;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return constructTree(0,0, grid.size() , grid);
    }
};


//Optimised

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* constructTree(int r,int c, int length, vector<vector<int>>& grid){

        if(length == 1) return new Node(grid[r][c], true);

        Node* topLeft = constructTree(r, c, length/2, grid);
        Node* topRight = constructTree(r, c+(length/2), length/2, grid);
        Node* bottomLeft = constructTree(r+(length/2), c, length/2, grid);
        Node* bottomRight = constructTree(r+(length/2), c+(length/2), length/2, grid);

        if(topLeft->isLeaf == true && topRight->isLeaf == true && bottomLeft->isLeaf == true && bottomRight->isLeaf == true && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val){
            return new Node(topLeft->val, true);
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        return constructTree(0,0, grid.size() , grid);
    }
};