class Solution {
    int find(vector<int>& dsuf, int v) {
        if (dsuf[v] == -1)
            return v;
        return dsuf[v] = find(dsuf, dsuf[v]);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> dsuf(26, -1);

        // Step-1: Build Disjoint Joint equivalent sets (with smallest in each
        // set as absolute parent)
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i])
                continue;

            int px = find(dsuf, s1[i] - 'a');
            int py = find(dsuf, s2[i] - 'a');
            if (px == py) // Already in same set
                continue;

            // Union by smallest char as absolute parent
            if (px > py)
                dsuf[px] = py;
            else
                dsuf[py] = px;
        }
        // Step-2: Iterate for baseStr and find lexicographical smallest
        // equivalent string
        string res;
        for (int i = 0; i < baseStr.size(); ++i) {
            int parent = find(dsuf, baseStr[i] - 'a');
            res.push_back(char(parent + 97));
        }
        return res;
    }
};