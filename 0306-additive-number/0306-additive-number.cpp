class Solution {
    string addStrings(const string &a, const string &b) {
        string res = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(const string &num, int start, vector<string> &seq) {
        if (start == num.size()) return seq.size() >= 3;

        for (int i = start; i < num.size(); ++i) {
            if (num[start] == '0' && i > start) break;
            string curr = num.substr(start, i - start + 1);

            int n = seq.size();
            if (n >= 2) {
                string sum = addStrings(seq[n - 2], seq[n - 1]);
                if (curr.size() < sum.size()) continue;
                if (curr > sum) break; 
                if (curr != sum) continue;
            }

            seq.push_back(curr);
            if (dfs(num, i + 1, seq)) return true;
            seq.pop_back();
        }

        return false;
    }

public:
    bool isAdditiveNumber(string num) {
        vector<string> seq;
        return dfs(num, 0, seq);
    }
};
