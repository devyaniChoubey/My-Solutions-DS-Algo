https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0, n = chalk.size();
        vector<long long>prefix(n, 0);

        prefix[0] = chalk[0];

        for(int i=1;i < n;i++) {
            prefix[i] = prefix[i-1] + chalk[i];
        }

        int rem = k%prefix[n-1];

        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(prefix[mid] <= rem){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low;
    }
};



//Solution 2
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0, n = chalk.size();

        for(int i=0;i < n;i++) {
            sum += chalk[i];
        }

        int rem = k%sum;

        int curSum = 0;

        for(int i=0;i < n;i++){
            curSum += chalk[i];
            if(curSum > rem) return i;
        }

        return 0;

    }
};