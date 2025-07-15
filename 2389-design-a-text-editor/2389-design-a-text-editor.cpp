class TextEditor {
    stack<char> st1, st2;

public:
    TextEditor() {
    }

    void addText(string text) {
        for (char ch : text) {
            st1.push(ch);
        }
    }

    int deleteText(int k) {
        int charCount = min(k, (int)st1.size());
        if (charCount == 0)
            return 0;
        int temp = charCount;
        while (temp > 0) {
            st1.pop();
            temp--;
        }
        return charCount;
    }

    string cursorLeft(int k) {
        int charCount = min(k, (int)st1.size());
        while (charCount) {
            char ch = st1.top();
            st1.pop();
            st2.push(ch);
            charCount--;
        }
        string ans = "";
        stack<char> temp;
        charCount = min(10, (int)st1.size());
        while (charCount) {
            char ch = st1.top();
            st1.pop();
            temp.push(ch);
            ans = ch + ans;
            charCount--;
        }
        while (!temp.empty()) {
            char ch = temp.top();
            temp.pop();
            st1.push(ch);
        }
        return ans;
    }

    string cursorRight(int k) {
        int charCount = min(k, (int)st2.size());
        while (charCount) {
            char ch = st2.top();
            st2.pop();
            st1.push(ch);
            charCount--;
        }
        string ans = "";
        stack<char> temp;
        charCount = min(10, (int)st1.size());
        while (charCount) {
            char ch = st1.top();
            st1.pop();
            temp.push(ch);
            ans = ch + ans;
            charCount--;
        }
        while (!temp.empty()) {
            char ch = temp.top();
            temp.pop();
            st1.push(ch);
        }
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */