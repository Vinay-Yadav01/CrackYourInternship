class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> mp;
        for (const string& idea : ideas) {
            mp[idea[0]].insert(idea.substr(1));
        }

        long long ans = 0;
        for (auto& [char1, set1] : mp) {
            for (auto& [char2, set2] : mp) {
                if (char1 >= char2) continue;  // avoid duplicate pairings

                int common = 0;
                for (const auto& suffix : set1) {
                    if (set2.find(suffix) != set2.end()) {
                        common++;
                    }
                }

                long long unique1 = set1.size() - common;
                long long unique2 = set2.size() - common;
                ans += 2LL * unique1 * unique2; // multiply by 2 for (a,b) and (b,a)
            }
        }
        return ans;
    }
};
