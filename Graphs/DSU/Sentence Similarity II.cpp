https://leetcode.com/problems/sentence-similarity-ii/description/

//DSU
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

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;


        unordered_map<string,int>mp;

        int id = 1;

        DisjointSet ds(4005);

        for(auto pair:similarPairs){
            int u, v;
            if(mp.find(pair[0]) == mp.end()){
                mp[pair[0]] = id;
                id++;
            }

            if(mp.find(pair[1]) == mp.end()){
                mp[pair[1]] = id;
                id++;
            }

            u = mp[pair[0]] , v = mp[pair[1]];

            ds.unionBySize(u, v);
        }

        
        for(int i=0;i < sentence1.size();i++){
            if(sentence1[i] == sentence2[i]) continue;

            if(mp.find(sentence1[i]) != mp.end() && mp.find(sentence2[i]) != mp.end() ){
                int u = mp[sentence1[i]] , v = mp[sentence2[i]];
                if(ds.findUPar(u) != ds.findUPar(v)) return false;
            }else return false;
            
        }

        return true;
    }
};




//Optimised DSU

class DisjointSet {
    public:
    unordered_map<string,string>parent;
    unordered_map<string,int>size;

    DisjointSet(){

    }

    void addWord(string word){
        if(!parent.count(word)){
            parent[word] = word;
            size[word] = 1;
        }
    }


    bool isWordPresent(string word){
       if(parent.count(word)) return true;
       return false;
    }


    string findUPar(string node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(string u, string v){
        string ulp_u = findUPar(u);
        string ulp_v = findUPar(v);

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

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;

        DisjointSet ds;

        for(auto pair:similarPairs){
            ds.addWord(pair[0]);
            ds.addWord(pair[1]);
            ds.unionBySize(pair[0], pair[1]);
        }

        
        for(int i=0;i < sentence1.size();i++){
            if(sentence1[i] == sentence2[i]) continue;

            if(ds.parent.find(sentence1[i]) != ds.parent.end() && 
            ds.parent.find(sentence2[i]) != ds.parent.end() && ds.findUPar(sentence1[i]) == ds.findUPar(sentence2[i])){

            }else return false;
            
        }

        return true;
    }
};