https://www.interviewbit.com/problems/minimum-parantheses/

int Solution::solve(string s) {
    int openingBrackets = 0, closingBrackets = 0;
    
    for(char ch:s){
        if(ch == '(') openingBrackets++;
        else{
            if(openingBrackets > 0) openingBrackets--;
            else closingBrackets++;
        }
    }
    
    return openingBrackets + closingBrackets;
}
