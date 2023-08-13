https://www.interviewbit.com/problems/maximum-edge-removal/

// As we need connected components that have even number of vertices so when we get one component we can remove the edge that connects it to the remaining tree 
// and we will be left with a tree with even number of vertices which will be the same problem 
// but of smaller size, we have to repeat this algorithm until the remaining tree cannot be decomposed further in the above manner.

// We will traverse the tree using DFS which will return the number of vertices in the component of which the current node is the root.

// If a node gets an even number of vertices from one of its children then the edge from that node to its child will be removed and result will be increased by one and 
// if the returned number is odd then we will add it to the number of vertices that the component will have if the current node is the root of it.

// Such that we can calculate the maximum number of nodes we can remove.



int maxEdges(int node,int par, vector<int>adj[], int A, int &ans){
    
    int nodesCnt = 1;
    for(auto it:adj[node]){
        if(it != par){
           nodesCnt += maxEdges(it, node, adj, A, ans);
        }
    }
    
    if(nodesCnt % 2 == 0) ans++;
    return nodesCnt;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];
    
    int ans = 0;
    
    for(auto it: B){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    maxEdges(1,-1, adj, A, ans);
    
    return ans-1;
}
