https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?source=submission-ac

//Brute Force

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>supply_set(supplies.begin(), supplies.end());
        bool mark[n];

        vector<string>ans;

        memset(mark, false, sizeof mark);

        bool keepIterating = true;

        while(keepIterating){
            
            keepIterating = false;
            for(int i=0;i < n;i++){
                bool flag = true;
                for(auto ingr:ingredients[i]){
                    if(supply_set.find(ingr) == supply_set.end()){
                        flag = false;
                        break;
                    }
                }

                if(mark[i] == false && flag == true){
                    mark[i] = true;
                    keepIterating = true;
                    supply_set.insert(recipes[i]);
                }
            }
        }

        for(int i=0;i < n;i++){
            if(mark[i]){
                ans.push_back(recipes[i]);
            }
        }

        return ans;
    }
};

//Topological Sort
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>supply_set(supplies.begin(), supplies.end());

        int n = recipes.size();

        unordered_map<string, vector<string>>graph;
        unordered_map<string, int>inDegree;

        for(int i=0;i < n;i++){
            for(auto ingr:ingredients[i]){
                if(supply_set.find(ingr) == supply_set.end()){
                    graph[ingr].push_back(recipes[i]);
                    inDegree[recipes[i]]++;
                }
            }
        }

        queue<string>q;

        for(int i=0;i < n;i++){
            if(inDegree[recipes[i]] == 0) q.push(recipes[i]);
        }

        vector<string>ans;

        while(!q.empty()){
            string recipe = q.front();
            q.pop();
            ans.push_back(recipe);
            
            for(auto it:graph[recipe]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        return ans;

    }
};