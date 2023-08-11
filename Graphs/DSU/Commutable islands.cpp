https://www.interviewbit.com/problems/commutable-islands/

class DisjointSet {
    public:
    vector<int>parent, rank, size;
    DisjointSet(int n){
       parent.resize(n+1);
       rank.resize(n+1,0);
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

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u; 
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

bool static comp(vector<int>&a , vector<int> &b){
    return (a[2] < b[2]);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    DisjointSet ds(A);
    sort(B.begin() , B.end(), comp);
    
    int ans = 0;
    for(auto it:B){
        if(ds.findUPar(it[0]) != ds.findUPar(it[1])){
            ans += it[2];
        }
        ds.unionBySize(it[0], it[1]); 
    }
    
    return ans;
}
