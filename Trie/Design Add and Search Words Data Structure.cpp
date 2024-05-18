https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

struct Node{
    Node* links[26];
    bool isWord = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void putKey(char ch, Node* node){
      links[ch - 'a'] = node;
    }

    Node* getNext(char ch){
        return links[ch - 'a'];
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->putKey(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }

        node->isWord = true;
    }

    bool searchWord(Node* root, string &word, int ind){

        if(ind == word.size() && root->isWord) return true;

        for(char ch='a';ch <= 'z';ch++){
            if((ch == word[ind] || word[ind] == '.') && root->containsKey(ch)){
                if(searchWord(root->getNext(ch), word, ind+1)) return true;
            }
        }

        return false;
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */