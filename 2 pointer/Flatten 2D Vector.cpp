https://leetcode.com/problems/flatten-2d-vector/

class Vector2D {
public:
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
    }

    int col = 0, row = 0;

    void advanceNext(){
        while(row < v.size() && col >= v[row].size()){
            col = 0;
            row++;
        }
    }
    
    int next() {
        advanceNext();
        return v[row][col++];
    }
    
    bool hasNext() {
        advanceNext();
        return row < v.size();
    }
};
