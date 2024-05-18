https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i=0;i < strs[0].length();i++){
            for(int j=1;j < strs.size();j++){
                if(i >= strs[j].size() || strs[j][i] != strs[j-1][i]) return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};


//Trie solution

struct Node {
    Node* links[26];
    bool isEnd = false;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void putKey(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNext(char ch){
        return links[ch-'a'];
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
        for(int i=0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->isEnd = true;
    }

    void findPrefix(Node* node, string &s){
        char c;
        int cnt = 0;
        for(char ch='a';ch <= 'z';ch++){
            if(node->containsKey(ch)){
                cnt++;
                c = ch;
            }
        }

        if(cnt == 1 && node->isEnd == false) {
            s += c;
            findPrefix(node->getNext(c), s);
        }
        else return;
    }

    

    string prefix(){
        string s = "";
        findPrefix(root, s);
        return s;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for(string &str:strs){
            trie.insert(str);
        }

        return trie.prefix();
    }
};


//Trie Solution 2
struct Node {
    Node* links[26];
    bool isEnd = false;
    int childrenCnt = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void putKey(char ch, Node* node){
        links[ch-'a'] = node;
        childrenCnt++;
    }

    Node* getNext(char ch){
        return links[ch-'a'];
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
        for(int i=0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->isEnd = true;
    }

    
    string prefix(string &word){
        Node* node = root;

        string ans = "";

        for(char ch:word){
            if(node->containsKey(ch) && node->isEnd == false && node->childrenCnt == 1){
                ans += ch;
                node = node->getNext(ch);
            }else break;
        }
        
        return ans;


    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for(string &str:strs){
            trie.insert(str);
        }

        return trie.prefix(strs[0]);
    }
};