https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int>visited(n, 0);

        dfs(0, visited,rooms);

        for(int i=0;i < n;i++){
            if(!visited[i]) return false;
        }

        return true;
    }

    void dfs(int room, vector<int>&visited, vector<vector<int>>& rooms){
        visited[room] = 1;

        for(auto it:rooms[room]){
            if(!visited[it]) dfs(it, visited, rooms);
        }
    }
};