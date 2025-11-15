class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push((dist[i]  + speed[i] - 1) / speed[i] );
            cout << (dist[i]  + speed[i] - 1) / speed[i] <<endl;
        }
        int time = 1;
        while(!pq.empty()){
            int curTime = pq.top();
            pq.pop();
            if(curTime < time) {
                pq.push(curTime);
                break;
            }
            time++;
        }
        return n - pq.size();
    }
};