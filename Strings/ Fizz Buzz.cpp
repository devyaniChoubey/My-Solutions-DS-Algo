https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans(n);

        for(int i=1;i <= n;i++){
            if(i % 3 == 0 && i % 5 == 0) ans[i-1] = "FizzBuzz";
            else if(i%3 == 0) ans[i-1] = "Fizz";
            else if(i % 5 == 0) ans[i-1] = "Buzz";
            else ans[i-1] = to_string(i);
        }

        return ans;
    }
};



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;

        for(int i=1;i <= n;i++){
            string str = "";
            if(i%3 == 0) str += "Fizz";
            if(i%5 == 0) str += "Buzz";
            
            if(str == "") str += to_string(i);

            ans.push_back(str);
        }

        return ans;
    }
};



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;

        map<int, string>hash;

        hash[3] = "Fizz";
        hash[5] = "Buzz";

        for(int i=1;i <= n;i++){
            string str = "";

            for(auto it:hash){
                if(i % it.first == 0) str += it.second;
            }
            
            if(str == "") str += to_string(i);

            ans.push_back(str);
        }

        return ans;
    }
};