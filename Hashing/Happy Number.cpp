https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

https://leetcode.com/problems/happy-number/editorial/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int getNext(int n){

        int sum = 0;
        while(n > 0){
           int d = (n%10);
           sum += (d*d);
           n = n/10;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;

        while(n != 1 && !seen.count(n)){
            seen.insert(n);
            n = getNext(n);
        }

        return (n == 1);
    }
};

class Solution {
public:
    int getNext(int n){

        int sum = 0;
        while(n > 0){
           int d = (n%10);
           sum += (d*d);
           n = n/10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(slow != 1){

            slow = getNext(slow);
            fast = getNext(getNext(fast));

            if(slow == fast) break;
        }

        return slow == 1;
    }
};