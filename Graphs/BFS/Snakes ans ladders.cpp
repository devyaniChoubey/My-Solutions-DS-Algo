https://leetcode.com/problems/snakes-and-ladders/description/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>>cells(n*n + 1);
        vector<int>columns(n);
        int ind = 1;
        

        iota(columns.begin() , columns.end(), 0);
        for(int row=n-1; row >= 0;row--){
            for(auto col:columns){
                cells[ind] = {row, col};
                ind++;
            }
            reverse(columns.begin(), columns.end());
        }

        vector<int>dist(n*n + 1, -1);

        queue<int>q;
        q.push(1);
        dist[1] = 0;
        int steps = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i < size;i++){
                int curr = q.front();
                q.pop();

                for(int i=curr+1;i <= min(curr+6, n*n);i++){
                    int row = cells[i].first;
                    int col = cells[i].second;
                    int destination = (board[row][col] == -1) ? i : board[row][col];
                    if(dist[destination] == -1){
                        dist[destination] = dist[curr] + 1;
                        q.push(destination);
                    }
                }
            }
            steps++;
        }

        return dist[n*n];
    }
};


//Method 2

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>>cells(n*n + 1);
        vector<int>columns(n);
        int ind = 1;
        

        iota(columns.begin() , columns.end(), 0);
        for(int row=n-1; row >= 0;row--){
            for(auto col:columns){
                cells[ind] = {row, col};
                ind++;
            }
            reverse(columns.begin(), columns.end());
        }

        vector<int>vis(n*n + 1, 0);

        queue<int>q;
        q.push(1);
        vis[1] = 1;
        int steps = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i < size;i++){
                int curr = q.front();
                q.pop();

                for(int i=curr+1;i <= min(curr+6, n*n);i++){
                    int row = cells[i].first;
                    int col = cells[i].second;
                    int destination = (board[row][col] == -1) ? i : board[row][col];
                    if(destination == n*n) return steps;
                    if(vis[destination] == 0){
                        q.push(destination);
                        vis[destination] = 1;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
