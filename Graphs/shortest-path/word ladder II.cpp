

//TLE SOLUTION

//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        vector<string>usedOnLevel;
        q.push({beginWord});
        usedOnLevel.push_back(beginWord);
        vector<vector<string>>ans;
        int level = 0;
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            if(vec.size() > level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();
            
            if(word == endWord){
                ans.push_back(vec);
            }
            for(int i=0;i < word.length();i++){
                char temp = word[i];
                for(char c ='a';c<='z';c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedOnLevel.push_back(word);
                    }
                }
                word[i] = temp;
            }
            
        }
        
        return ans;
         
        
    }
};


//TLE SOLUTION

//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<vector<string>>q;
        unordered_set<string>s(wordList.begin(), wordList.end());
        q.push({beginWord});
        bool found = false;
        vector<vector<string>>ans;
        
        while(!q.empty()){
            int size = q.size();
            vector<string>usedOnLevel;
            for(int i=0;i < size;i++){
                vector<string>cur = q.front();
                q.pop();
                string lastWord = cur.back();
                if(lastWord == endWord){
                    ans.push_back(cur);
                    found = true;
                }
                
                for(int j=0;j < lastWord.length();j++){
                   char temp = lastWord[j];
                   for(char c='a'; c <= 'z'; c++){
                       lastWord[j] = c;
                       if(s.find(lastWord) != s.end()){
                           cur.push_back(lastWord);
                           q.push(cur);
                           usedOnLevel.push_back(lastWord);
                           cur.pop_back();
                       }
                   }
                   lastWord[j] = temp;
                   
                }
            }
            
            if(found) return ans;
            
            for(auto it:usedOnLevel) s.erase(it);
            
        }
    }
};






//Accepted

class Solution {
    vector<vector<string>>ans;
    unordered_map<string, int>mp;
    string b;

public:
    void dfs(string word, vector<string>&sequence){

        if(word == b){
            reverse(sequence.begin(), sequence.end());
            ans.push_back(sequence);
            reverse(sequence.begin(), sequence.end());
            return;
        }
         
        int step = mp[word];
        for(int i=0;i < word.size(); i++){
            char temp = word[i];
            for(char c='a'; c <= 'z'; c++){
                word[i] = c;
                if(mp.find(word) != mp.end() && mp[word] == step - 1){
                    sequence.push_back(word);
                    dfs(word, sequence);
                    sequence.pop_back();
                }
            }
            word[i] = temp;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>st(wordList.begin(), wordList.end());
        mp[beginWord] = 1;
        b = beginWord;
        st.erase(b);
        while(!q.empty()){
            string s = q.front();
            q.pop();
            
            if(s == endWord) break;
            int step = mp[s];
            for(int i=0;i < s.length();i++){
                char temp = s[i];
                for(char c='a'; c <= 'z';c++){
                   s[i] = c;
                   if(st.find(s) != st.end()){
                       q.push(s);
                       st.erase(s);
                       mp[s] = step + 1;
                   }
                }
                s[i] = temp;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string>sequence;
            sequence.push_back(endWord);
            dfs(endWord, sequence);
        }

        return ans;


    }
};