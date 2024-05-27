https://leetcode.com/problems/moving-average-from-data-stream/
class MovingAverage {
public:
    int windSize;
    double sum = 0;
    queue<int>q;
    MovingAverage(int size) {
        windSize = size;
    }
    
    double next(int val) {
        if(q.size() >= windSize){
            sum -= q.front();
            q.pop();
        }

        sum += val;
        q.push(val);

        return sum/q.size();
    }
};