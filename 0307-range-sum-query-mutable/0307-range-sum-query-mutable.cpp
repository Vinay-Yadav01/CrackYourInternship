class NumArray {
    int n, x;
    int* st;
    vector<int> arr;
    int constructSTUtil(vector<int>& arr, int ss, int se, int* st, int si) {
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
        int mid = getMid(ss, se);
        st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
        return st[si];
    }
    int getMid(int s, int e) { return s + (e - s) / 2; }
    int getSumUtil(int* st, int ss, int se, int qs, int qe, int si) {
        if (qs <= ss && qe >= se)
            return st[si];

        if (se < qs || ss > qe)
            return 0;

        int mid = getMid(ss, se);
        return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
               getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
    }

    void updateValueUtil(int* st, int ss, int se, int i, int diff, int si) {
        if (i < ss || i > se)
            return;

        st[si] = st[si] + diff;
        if (se != ss) {
            int mid = getMid(ss, se);
            updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
            updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
        }
    }

public:
    NumArray(vector<int>& arr) {
        this->arr = arr;
        n = arr.size();
        arr = arr;
        cout << n << endl;
        x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        st = new int[max_size];
        constructSTUtil(arr, 0, n - 1, st, 0);
    }

    void update(int i, int val) {
        if (i < 0 || i > n - 1) {
            return;
        }
        int diff = val - arr[i];
        arr[i] = val;
        updateValueUtil(st, 0, n - 1, i, diff, 0);
    }

    int sumRange(int qs, int qe) {
        if (qs < 0 || qe > n - 1 || qs > qe) {
            return -1;
        }

        return getSumUtil(st, 0, n - 1, qs, qe, 0);
    }
};
