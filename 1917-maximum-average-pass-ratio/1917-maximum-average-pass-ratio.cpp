class Solution {
    double gain(int pass, int total) {
        return (pass + 1.0) / (total + 1.0) - (pass * 1.0) / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // max heap: store {gain, pass, total}
        priority_queue<tuple<double, int, int>> pq;

        for (auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            pq.push({gain(pass, total), pass, total});
        }

        while (extraStudents--) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            pass++, total++;
            pq.push({gain(pass, total), pass, total});
        }

        double acc = 0;
        while (!pq.empty()) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            acc += (double)pass / total;
        }

        return acc / classes.size();
    }
};
