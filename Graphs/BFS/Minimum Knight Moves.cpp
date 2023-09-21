https://leetcode.com/problems/minimum-knight-moves/description/


// On the right/top side, we also limit the movement by max 
//  2 blocks out of the target. I think the performance gain is likely because of this reduced board size.

// Because I am using an array instead of a hashmap, we have to expand 
// the board by 2 blocks at each side, from (0,0)->(x,y) to (-2, -2)->(x+2, y+2). 
// Since array doesn't allow negative indices, I transform the expanded board to (0,0)->(x+4, y+4).


class Solution {
public:
    int minKnightMoves(int x, int y) {
        int delRow[] = {-1, -2, -2, -1, +1, +1, +2, +2};
        int delCol[] = {-2,  -1, +1, +2, -2, +2, -1, +1};


        x = abs(x);
        y = abs(y);

        int sizeX = x + 4, sizeY = y + 4;

        vector<vector<int>>board(sizeX , vector<int>(sizeY , 0));

        if(x == 0 && y == 0) return 0;
        
        queue<pair<int,int>>q;


        q.push({0, 0});
        board[2][2] = 1;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            for(int k=0;k < size;k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(x == row && y == col) return steps;

                for(int i=0;i < 8;i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    
                    int r = nRow + 2, c = nCol + 2;
                    if(r >= 0 && r < sizeX && c < sizeY && c >= 0 && board[r][c] == 0){
                        q.push({nRow, nCol});
                        board[r][c] = 1;
                    }
                }
            }
            steps++;

        }

        return steps;


    }
};