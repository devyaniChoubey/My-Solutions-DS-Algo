https://leetcode.com/problems/cousins-in-binary-tree/description/


//DFS solution

class Solution {
public:
    TreeNode* parentX = NULL; TreeNode* parentY = NULL;
    int depthX = 0, depthY = 0;
    void dfs(TreeNode* root, int x, int y, int level){
        if(root == NULL) return;

        if((root->left && root->left->val == x) || (root->right && root->right->val == x)){
            parentX = root;
            depthX = level+1;
        }

        if((root->left && root->left->val == y) || (root->right && root->right->val == y)){
            parentY = root;
            depthY = level+1;
        }

        dfs(root->left, x , y, level+1);
        dfs(root->right, x , y, level+1);


    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x , y, 0);
        if(parentX != parentY && depthX == depthY) return true;
        else return false;
    }
};

//BFS 

class Solution {
public:
    
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            bool Xexist = false , Yexist = false;
            for(int i=0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->val == x) Xexist = true;
                if(node->val == y) Yexist = true;

                if(node->left && node->right){
                    if(node->left->val == x && node->right->val == y){
                        return false;
                    }

                    if(node->left->val == y && node->right->val == x){
                        return false;
                    }
                }
                
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);


            }
            if(Xexist && Yexist) return true;
        }

        return false;
    }
};