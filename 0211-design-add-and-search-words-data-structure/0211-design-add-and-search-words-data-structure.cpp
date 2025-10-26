class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
private:
    TrieNode* root = new TrieNode();
    
    bool search(string& word, int idx, TrieNode* node) {
        for (int i = idx; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word, i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
    }
};