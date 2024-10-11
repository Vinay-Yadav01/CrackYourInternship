class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        vector<int> chair(n,-1);
        for(auto time: times){
            int arrives = time[0];
            int depart = time[1];
            for(int i=0;i<n;i++){
                if(chair[i]<=arrives){
                    chair[i] = depart;
                    if(targetTime == arrives) return i;
                    break;
                }
            }
        }
        return n;
    }
};