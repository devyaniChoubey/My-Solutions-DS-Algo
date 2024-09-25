
https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24

struct Node{
    Node *links[10];

    bool containsKey(char ch){
        return links[ch-'0'] != NULL;
    }

    void putsKey(char ch, Node* next){
        links[ch-'0'] = next;
    }

    Node* getKey(char ch){
        return links[ch-'0'];
    }
};

class Trie {
    private: Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                node->putsKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
        }
    }

    int search(string word){
        Node* node = root;
        
        for(int i=0;i < word.size();i++){
            if(!node->containsKey(word[i])){
                return i;
            }else{
                node = node->getKey(word[i]);
            }
        }

        return word.size();
        
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int i=0;i < arr1.size();i++){
            trie.insert(to_string(arr1[i]));
        }

        int maxLen = 0;

        for(int i=0;i < arr2.size();i++){
            maxLen = max(maxLen, trie.search(to_string(arr2[i])));
        }

        return maxLen;
    }
};