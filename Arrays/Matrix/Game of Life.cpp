https://leetcode.com/problems/game-of-life/?envType=company&envId=google&favoriteSlug=google-six-months&difficulty=EASY%2CMEDIUM&status=TO_DO

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>copy = board;
        int n = board.size();
        int m = board[0].size();
        int delRow[] = {-1, 0, 1, 0, -1, 1, -1,1};
        int delCol[] = {0, -1, 0, 1, 1, -1, -1,1};

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                int zeroCnt = 0;
                int oneCnt = 0;
                for(int k=0;k < 8;k++){
                    int nRow = i + delRow[k];
                    int nCol = j + delCol[k];

                    if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m) continue;
                    
                    if(copy[nRow][nCol] == 1) oneCnt++;
                    if(copy[nRow][nCol] == 0) zeroCnt++;
                }

                if(board[i][j] == 1 && oneCnt < 2) board[i][j] = 0;
                else if(board[i][j] == 1 && (oneCnt == 2 || oneCnt ==3)) board[i][j] = 1;
                else if(board[i][j] == 1 && oneCnt > 3) board[i][j] = 0;
                else if(board[i][j] == 0 && oneCnt == 3) board[i][j] = 1;
            }
        }

    }
};



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delRow[] = {-1, 0, 1, 0, -1, 1, -1,1};
        int delCol[] = {0, -1, 0, 1, 1, -1, -1,1};

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                int zeroCnt = 0;
                int oneCnt = 0;
                for(int k=0;k < 8;k++){
                    int nRow = i + delRow[k];
                    int nCol = j + delCol[k];

                    if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m) continue;
                    
                    if(board[nRow][nCol] == -1 || board[nRow][nCol] == 1) oneCnt++;
                }

                if(board[i][j] == 1 && oneCnt < 2) board[i][j] = -1;
                else if(board[i][j] == 1 && oneCnt > 3) board[i][j] = -1;
                else if(board[i][j] == 0 && oneCnt == 3) board[i][j] = 2;
            }
        }

        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
               if(board[i][j] == -1) board[i][j] = 0;
               if(board[i][j] == 2) board[i][j] = 1;
            }
        }

    }
};