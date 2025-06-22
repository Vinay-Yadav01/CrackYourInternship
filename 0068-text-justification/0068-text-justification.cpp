class Solution {
    string generateSpaces(int occ) {
        string str = "";
        while (occ--) {
            str += " ";
        }
        return str;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, line;
        int len = 0;

        for (string word : words) {
            if (len + line.size() + word.size() > maxWidth) {
                int extra_spaces = maxWidth - len;
                int spaces = extra_spaces / max(1, (int)line.size() - 1);
                int remaining = extra_spaces % max(1, (int)line.size() - 1);
                string curr = "";
                int i = 0;
                for (i = 0; i < max(1, (int)line.size() - 1); i++) {
                    curr += line[i];
                    curr += generateSpaces(spaces + (remaining-- > 0 ? 1 : 0));
                }
                if (i < line.size())
                    curr += line[i]; // last word in the line
                ans.push_back(curr);
                line.clear();
                len = 0;
            }
            line.push_back(word);
            len += word.size();
        }

        // Last line - left justified
        string curr = "";
        for (int i = 0; i < line.size(); i++) {
            curr += line[i];
            if (i != line.size() - 1)
                curr += " ";
        }
        curr += generateSpaces(maxWidth - curr.size());
        ans.push_back(curr);

        return ans;
    }
};
