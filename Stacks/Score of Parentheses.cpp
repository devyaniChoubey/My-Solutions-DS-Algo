https://leetcode.com/problems/score-of-parentheses/description/


https://leetcode.com/problems/score-of-parentheses/solutions/1856699/c-beats-100-omg-o-1-space-explained/
Let's take a look how do we calculate the score on following examples:

()() => 1+1
(()()) => 2*(1+1)
((()())) => 2*2*(1+1)
((()(()))) => 2*2*(1+2*1)

We can see that any () in the string gives a score depending on its depth. If () is located on the higher possible level (depth=0), 
the score is simply a 1. If it's located deeper, we just multiply it by 2 as many times as its depth. The found score we can just add to the final result.
Why can we do that? Remember that, for example, this expression 2*2*(1+1) can be expressed as 2*2+2*2. 
No matter how deep parenthesis, the final expression of score can be represented as a sum of () scores.

Time: O(N) - traversing
Space: O(1)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, depth = 0;
        char prev;

        for(char c:s){
            if(c == '(') depth++;
            else{
               depth--;
               if(prev == '(') res += (1 << depth);  
            }

            prev = c;
        }

        return res;
    }
};




Time: O(N) - traversing
Space: O(N)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int>st;
        
        for(int i=0;i < s.length(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }else{
                score = st.top() + max(2*score, 1);
                st.pop();
            }
        }

        return score;
    }
};