https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/

struct Node{

    map<char, Node*>links;

    bool containsKey(char ch){
        return (links.find(ch) != links.end());
    }

    void putKey(char ch, Node *node){
        links[ch] = node;
    }

    Node* get(char ch){
        return links[ch];
    }
};

class Solution {
public:
    int countDistinct(string &s) {
        Node* root = new Node();
        int substrCnt = 0;

        for(int i=0;i < s.length();i++){
            Node* node = root;
            for(int j=i;j < s.length();j++){
                if(!node->containsKey(s[j])){
                    node->putKey(s[j], new Node());
                    substrCnt++;
                }
                node = node->get(s[j]);
            }
        }

        return substrCnt;
    }
};