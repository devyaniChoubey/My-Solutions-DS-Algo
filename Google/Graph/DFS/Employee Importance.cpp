https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

void dfs(int id, vector<int>adj[], vector<int>&importance, int &totalImportance){
    totalImportance += importance[id];
    for(auto it:adj[id]){
        dfs(it, adj, importance, totalImportance);
    }
}
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<int>adj[2001];
        vector<int>importance(2001);

        for(int i=0;i < employees.size();i++){
            for(auto it:employees[i]->subordinates){
               adj[employees[i]->id].push_back(it);
            }
            importance[employees[i]->id] = employees[i]->importance;
        }
        int totalImportance = 0;
        dfs(id, adj, importance, totalImportance);
        return totalImportance;
    }
};




/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


class Solution {
public:
    unordered_map<int, Employee*>emap;

    void dfs(int id, int &totalImportance){
        totalImportance += emap[id]->importance;
        for(auto it:emap[id]->subordinates){
            dfs(it,totalImportance);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        vector<int>adj[2001];
        vector<int>importance(2001);

        for(auto it:employees){
            emap[it->id] = it;
        }

        int totalImportance = 0;
        dfs(id, totalImportance);
        return totalImportance;
    }
};