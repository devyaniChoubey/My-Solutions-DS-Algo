https://www.interviewbit.com/problems/file-search/

class DisjointSet {
    public:
    vector<int>parent, size;
    DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i <= n;i++) parent[i] = i;
    }


    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    DisjointSet ds(A);
    
    set<int>s;
    
    for(auto it:B) ds.unionBySize(it[0], it[1]);
    
    for(int i=1;i <= A;i++){
        s.insert(ds.findUPar(i));
    }
    
    return s.size();
    
}


//Method 2

class DisjointSet {
    public:
    vector<int>parent, size;
    DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0;i <= n;i++) parent[i] = i;
    }


    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    DisjointSet ds(A);
    
    for(auto it:B) {
        if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
            A--;
            ds.unionBySize(it[0], it[1]);
        }
    }
    
    return A;
    
}
