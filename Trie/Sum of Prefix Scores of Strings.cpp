https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=daily-question&envId=2024-09-25


struct Node {
    Node* links[26];
    int prefixCnt = 0;

    bool containsKey(char ch){
       return (links[ch-'a'] != NULL);
    }

    void putKey(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
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
                node->putKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
            node->prefixCnt++;
        }
    }

    int countAns(string word){
        Node* node = root;
        int ans = 0;
        for(int i=0;i < word.size();i++){
            node = node->getKey(word[i]);
            ans += node->prefixCnt;
        }
        return ans;
    }

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(string &word:words){
            trie.insert(word);
        }

        vector<int>ans;

        for(string &word:words){
            ans.push_back(trie.countAns(word));
        }

        return ans;
    }
};