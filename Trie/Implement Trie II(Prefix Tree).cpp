https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/

struct Node {
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie {
private: Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }

            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    
    int countWordsEqualTo(string word) {
        Node* node = root;

        for(int i=0;i < word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getEnd();
    }
    
    int countWordsStartingWith(string prefix) {
        Node* node = root;

        for(int i=0;i < prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }

            node = node->get(prefix[i]);
        }

        return node->getPrefix();
    }
    
    void erase(string word) {
        Node* node = root;

        for(int i=0;i < word.length();i++){
            if(!node->containsKey(word[i])) return;
            else {
                node = node->get(word[i]);
                node->reducePrefix();
            }
        }
        node->deleteEnd();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */