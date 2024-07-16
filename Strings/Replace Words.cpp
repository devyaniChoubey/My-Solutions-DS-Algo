https://leetcode.com/problems/replace-words/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>seen(dictionary.begin() , dictionary.end());

        stringstream ss(sentence);

        string word;

        string ans = "";

        while(getline(ss, word, ' ')){
            bool found = false;
            for(int i=1;i <= word.length();i++){
                if(seen.count(word.substr(0, i))){
                    ans += word.substr(0, i) + " ";
                    found = true;
                    break;
                }
            }
            if(!found) ans += word + " ";
        }

        ans.pop_back();

        return ans;
    }
};





struct Node{
    Node* links[26];
    bool isWord = false;

    bool containsKey(char &ch){
        return (links[ch-'a'] != NULL);
    }

    void putKey(char &ch, Node* next){
        links[ch-'a'] = next;
    }

    Node* getNext(char &ch){
        return links[ch-'a'];
    }
};

class Solution {
public:
    Node* root = new Node();

    void addWord(string &word){
        Node* node = root;

        for(char &c:word){
            if(!node->containsKey(c)){
                node->putKey(c, new Node());
            }
            node = node->getNext(c);
        }

        node->isWord = true;
    }

    string checkWord(string word){
        Node* node = root;

        for(int i=0;i < word.size();i++){
            if(node->containsKey(word[i])){
                node = node->getNext(word[i]);
                if(node->isWord) return word.substr(0, i+1);
            }else{
                if(node->isWord) return word.substr(0, i);
                else return word;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        for(string &st:dictionary){
            addWord(st);
        }

        stringstream ss(sentence);

        string word;

        string ans = "";

        while(getline(ss, word, ' ')){
            ans += checkWord(word) + " ";
        }

        ans.pop_back();

        return ans;
    }
};