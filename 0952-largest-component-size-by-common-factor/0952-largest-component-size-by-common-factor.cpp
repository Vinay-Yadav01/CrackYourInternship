class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        DSU dsu(maxVal + 1);

        // Union numbers with their factors
        for (int x : nums) {
            for (int f = 2; f * f <= x; f++) {
                if (x % f == 0) {
                    dsu.unite(x, f);
                    dsu.unite(x, x / f);
                }
            }
        }

        unordered_map<int, int> componentCount;
        int ans = 0;

        for (int x : nums) {
            int root = dsu.find(x);
            ans = max(ans, ++componentCount[root]);
        }

        return ans;
    }
};
