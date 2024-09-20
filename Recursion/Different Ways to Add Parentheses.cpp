https://leetcode.com/problems/different-ways-to-add-parentheses/?envType=daily-question&envId=2024-09-19

class Solution {
public:
    vector<int> solve(int start, int end, string &expression){
        if(start == end) return {int(expression[start] - '0')};
        if(end-start == 1) return {stoi(expression.substr(start, 2))};

        vector<int>ans;

        for(int i=start;i <= end;i++){
            if(isdigit(expression[i])) continue;

            vector<int>left = solve(start, i-1, expression);
            vector<int>right = solve(i+1, end, expression);

            for(int &l:left){
                for(int &r:right){
                    int res;
                    if(expression[i] == '+') res = l + r;
                    else if(expression[i] == '*') res = l * r;
                    else if(expression[i] == '-') res = l - r;
                    
                    ans.push_back(res);
                }
            }
        }

        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(0, expression.length() - 1, expression);
    }
};