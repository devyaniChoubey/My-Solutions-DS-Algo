https://www.interviewbit.com/problems/tushars-birthday-bombs/

// Hint 1
// If you are Greedy and want to give the maximum no. of kicks, which friends would you choose to give the kicks?

// Greedy works :)

// Solution Approach
// Observations:

// Let the index of friend with minimum strength be F. (Take smallest index in case of a tie)

// It is obvious that -> Maximum no. of kicks = R/(S[F]).

// This is the length of the answer but since we need lexicographically smaller order (according to index), friends whose index is less than the F can also hit provided they do not change the length of the answer. There is also a crucial observation here, we need not consider the friend which have a friend to their left (lesser index) and have lesser than or equal strength than him. (Otherwise we can just take that friend with lesser index instead).

// Below is an example to clear the things out:

// R = 11, S = [6, 8, 5, 4, 7]

// In this case: Max no. of kicks = 11/4 = 2.

// answer = [3,3] (if we do not consider the lexicographic order)

// But answer may be [0,3] or [0,2] or [2,3] as they also have the same length.

// Here, only required friends to consider are newS = [6,5,4] as we will rather choose friend with strength 6 than choosing a friend with strength 8, and rather choose any of [6,5,4] than choosing friend with strength 7. (Give it a thought, it's true because our answer should be lexicographically smallest)

// Note that the friend with the minimum strength will be the last element of our newS vector (as newS will be in strict decreasing order)

// Algorithm:

// Find the max no. of kicks (length of our answer).
// Make a new S vector which only takes the friends that can be in the answer.
// Iterate through the S vector formed above and see if the friend at consideration can be used instead of the friend with minimum strength.
// If he can be successfully used then use him instead of the friend with minimum strength to get a lexicographically smaller answer.
// Can you code it?

vector<int> Solution::solve(int A, vector<int> &B) {
    int prev = INT_MAX;
    vector<pair<int,int>>newB;
    for(int i=0;i < B.size();i++){
        if(B[i] < prev){
            newB.push_back({i, B[i]});
            prev = B[i];
        }
    }
    
    int temp = prev;
    int i = 0;
    vector<int>ans;
    int n = newB.size();
    int R = A;
    
    while(i < n){
        if(newB[i].second <= R && (1 + (R - newB[i].second)/temp) == (R)/temp){
            ans.push_back(newB[i].first);
            R -= newB[i].second;
        }else i++;
    }
    
    return ans;
}