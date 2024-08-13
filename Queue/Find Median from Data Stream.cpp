https://leetcode.com/problems/find-median-from-data-stream/?envType=company&envId=google&favoriteSlug=google-thirty-days

class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int> > right;
    priority_queue <int> left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return ((double)left.top() + (double)right.top())/2.0;
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */