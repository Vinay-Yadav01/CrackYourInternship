class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> string_stack;
        stack<int> freq_stack;
        int i = 0;
        while (i < n) {
            if (s[i] == ']') {
                string str = "";
                while (!string_stack.empty() && string_stack.top() != "[") {
                    str = string_stack.top() + str;
                    string_stack.pop();
                }
                string_stack.pop();
                int freq = freq_stack.top();
                freq_stack.pop();
                string result = "";
                while (freq--) {
                    result += str;
                }
                string_stack.push(result);
                i++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                string str = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    str = str + s[i];
                    i++;
                }
                int num = stoi(str);
                freq_stack.push(num);
            } else {
                string_stack.push(string(1, s[i]));
                i++;
            }
        }
        string final_decoded_string = "";
        while (!string_stack.empty()) {
            final_decoded_string = string_stack.top() + final_decoded_string;
            string_stack.pop();
        }
        return final_decoded_string;
    }
};