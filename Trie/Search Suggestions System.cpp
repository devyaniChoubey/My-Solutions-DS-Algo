https://leetcode.com/problems/search-suggestions-system/

struct Node {
    Node* links[26];
    bool isWord = false;

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

    void insert(string &word){
        Node* node = root;

        for(int i=0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }

        node->isWord = true;
    }

    void dfs(string &prefix, Node* node, vector<string>&res){
        if(res.size() == 3) return;
        if(node->isWord){
            res.push_back(prefix);
        }
        for(char ch='a';ch <= 'z';ch++){
            if(node->links[ch-'a']){
                prefix.push_back(ch);
                dfs(prefix, node->links[ch-'a'], res);
                prefix.pop_back();
            }
        }
    }

    vector<string>getPrefix(string &prefix){
        vector<string>res;

        Node* node = root;

        for(int i=0;i < prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return res;
            }
            node = node->getNext(prefix[i]);
        }

        dfs(prefix, node, res);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;

        for(string &product:products){
            trie.insert(product);
        }

        vector<vector<string>>ans;

        string prefix;
        for(char &ch:searchWord){
            prefix += ch;
            ans.push_back(trie.getPrefix(prefix));
        }

        return ans;
    }
};