class Solution {
    #define pii pair<int,int>  // Define a shorthand for pair of integers
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();  
        vector<pii> events;  
        for(int i = 0; i < n; ++i) {
            events.push_back({intervals[i][0], 1});
            events.push_back({intervals[i][1] + 1, -1});
        }
        sort(events.begin(), events.end());

        int overlap = 0;  
        int max_overlap = 0;
        for(auto& event: events) {
            if(event.second == 1) 
                overlap++; 
            else                
                overlap--; 
            max_overlap = max(max_overlap, overlap);
        }
        return max_overlap;
    }
};