https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/

//brute force

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){

                if((i == 0 || (board[i-1][j] == '#')) && m-i >= len){
                    //cout << i << j << endl;
                    int row = i;
                    for(int k=0;k < len;k++){
                        //cout << row << j << k << endl;
                        if(board[row][j] == word[k] || board[row][j] == ' '){ row++;}
                        else break;
                        if(k == len-1 && (row == m || board[row][j] == '#')) {
                           cout << '0' << row << j << endl;
                           return true;
                        }
                    }
                }

                if((i == m-1 || (board[i+1][j] == '#')) && (i+1) >= len){
                    int row = i;
                    for(int k=0;k < len;k++){
                        if(board[row][j] == word[k] || board[row][j] == ' '){ row--;}
                        else break;
                        if(k == len-1 && (row == -1 || board[row][j] == '#')) {
                           cout << '1' << row << j << endl;
                           return true;
                        }
                    }
                }

                if((j == 0 || (board[i][j-1] == '#')) && n-j >= len){
                    int col = j;
                    for(int k=0;k < len;k++){
                        if(board[i][col] == word[k] || board[i][col] == ' '){ col++;}
                        else break;
                        if(k == len-1 && (col == n || board[i][col] == '#')) {
                           cout << '2' << i << col << endl;
                           return true;
                        }
                    }
                }

                if((j == n-1 || (board[i][j+1] == '#')) && (j+1) >= len){
                    int col = j;
                    for(int k=0;k < len;k++){
                        if(board[i][col] == word[k] || board[i][col] == ' '){ col--;}
                        else break;
                        if(k == len-1 && (col == -1 || board[i][col] == '#')) {
                           cout << '3' << i << col << endl;
                           return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};


// clever


class Solution {
public:
    bool check(vector<vector<char>>& board, string word){
        int m = board.size();
        int n = board[0].size();
        int len = word.size();

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if((i == 0 || (board[i-1][j] == '#')) && m - i >= len){
                    int row = i;

                    for(int k=0;k < len;k++){
                        if(board[row][j] == word[k] || board[row][j] == ' ') row++;
                        else break;

                        if(k == len-1 && (row == m || board[row][j] == '#')) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        vector<vector<char>>transposed(n, vector<char>(m , ' '));
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                transposed[j][i] = board[i][j];
            }
        }

        return check(board, word) || check(board, string(rbegin(word), rend(word))) || check(transposed, word) || check(transposed, string(rbegin(word), rend(word)));
    }
};