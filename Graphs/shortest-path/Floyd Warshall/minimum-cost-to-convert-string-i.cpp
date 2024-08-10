https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>matrix(26, vector<long long>(26, INT_MAX));

        for(int i=0;i < original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            matrix[u][v] = min((long long)cost[i] , matrix[u][v]);
        }

        for(int i=0;i < 26;i++){
            for(int j=0;j < 26;j++){
                if(i == j) matrix[i][j] = 0;
            }
        }

        for(int via=0;via < 26;via++){
            for(int i=0;i < 26;i++){
                for(int j=0;j < 26;j++){
                    matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
                }
            }
        }
        

        long long totalCost = 0;

        for(int i=0;i < source.size();i++){
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(matrix[u][v] == INT_MAX) return -1;
            else totalCost += matrix[u][v];
        }

        return totalCost;
    }
};