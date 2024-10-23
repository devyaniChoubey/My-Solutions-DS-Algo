https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28

class MyCircularDeque {
public:
    deque<int>dq;
    int k;
    MyCircularDeque(int cap) {
      k = cap;
    }
    
    bool insertFront(int value) {
      if(dq.size() >= k) return false;
      dq.push_front(value);
      return true;
    }
    
    bool insertLast(int value) {
      if(dq.size() >= k) return false;
      dq.push_back(value);
      return true;
    }
    
    bool deleteFront() {
      if(dq.empty()) return false;
      dq.pop_front();
      return true;
    }
    
    bool deleteLast() {
      if(dq.empty()) return false;
      dq.pop_back();
      return true;
    }
    
    int getFront() {
      if(dq.empty()) return -1;
      return dq.front();
    }
    
    int getRear() {
        if(dq.empty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return (dq.size() == k);
    }
};
