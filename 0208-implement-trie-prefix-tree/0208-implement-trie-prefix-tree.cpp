class TrieNode {
    TrieNode* children[26];
    bool flag;

public:
    TrieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    bool containChar(char ch) { return children[ch - 'a'] != nullptr; }

    void putChar(char ch) {
        TrieNode* next = new TrieNode();
        children[ch - 'a'] = next;
    }

    TrieNode* getChar(char ch) { return children[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containChar(ch)) {
                node->putChar(ch);
            }
            node = node->getChar(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containChar(ch)) {
                return false;
            }
            node = node->getChar(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (!node->containChar(ch)) {
                return false;
            }
            node = node->getChar(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */