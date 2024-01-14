https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string temp;
        unordered_map<char, string>hash1;
        unordered_map<string, char>hash2;

       

        for(int i=0;i < pattern.length();i++){
            getline(ss, temp, ' ');
            
            if(hash1.find(pattern[i]) != hash1.end() || hash2.find(temp) != hash2.end()){
                if(hash1[pattern[i]] != temp || hash2[temp] != pattern[i])return false;
            }else{
                hash1[pattern[i]] = temp;
                hash2[temp] = pattern[i];
            }
        }

        

        while(getline(ss, temp, ' ')){
            return false;
        }


        return true;
    }
};