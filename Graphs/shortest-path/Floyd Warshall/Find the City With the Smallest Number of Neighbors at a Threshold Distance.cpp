https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        for(int i=0;i < n;i++){
            dist[i][i] = 0;
        }

        for(int i=0;i < edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        
        for(int via=0;via < n;via++){
            for(int i=0;i < n;i++){
                for(int j=0;j < n;j++){
                    dist[i][j] = min(dist[i][j] , (dist[i][via] + dist[via][j]));
                }
            }
        }

        int ans = 0;
        int minCities = 1e9;
        for(int i=0;i < n;i++){
            int count = 0;
            for(int j=0;j < n;j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= minCities) {
                ans = i;
                minCities = count;
            }
        }

        return ans;



    }
};