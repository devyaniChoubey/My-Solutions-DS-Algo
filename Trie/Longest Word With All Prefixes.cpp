https://leetcode.com/problems/longest-word-with-all-prefixes/

struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getKey(char ch){
        return links[ch - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
};

class Trie {
private: Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;

        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
        }

        node->setEnd();
    }

    bool checkIfPrefixExist(string word){
        Node *node = root;
        
        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])) return false;
            else{
                node = node->getKey(word[i]);
                if(!node->isEnd()) return false;
            }
        }

        return true;
    }

};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;

        for(string word:words){
            trie.insert(word);
        }

        string ans = "";

        for(string word:words){
            if(trie.checkIfPrefixExist(word)){
                if(word.length() > ans.length()){
                    ans = word;
                }else if(word.length() == ans.length() && word < ans){
                    ans = word;
                }
            }
        }

        return ans;
    }
};