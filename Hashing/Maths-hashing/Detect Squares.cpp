https://leetcode.com/problems/detect-squares/

https://leetcode.com/problems/detect-squares/solutions/1471958/c-java-python-2-approaches-using-hashmap-with-picture-clean-concise/

class DetectSquares {
public:
    int cnt[1001][1001] = {0};
    vector<pair<int,int>>points;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0] , y = point[1];
        cnt[x][y]++;
        points.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int ans = 0;

        int x1 = point[0], y1 = point[1];

        for(auto it:points){
            int x3 = it.first, y3 = it.second;

            if(abs(x3-x1) == abs(y3-y1) && abs(x3-x1) > 0){
                ans += cnt[x3][y1]*cnt[x1][y3];
            }
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */