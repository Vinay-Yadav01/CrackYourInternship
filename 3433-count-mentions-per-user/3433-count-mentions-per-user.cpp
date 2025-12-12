class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<bool> isOnline(numberOfUsers, true);
        vector<int> backOnlineTime(numberOfUsers, -1);
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            if (stoi(a[1]) < stoi(b[1])) return true;
            else if(stoi(a[1]) == stoi(b[1])) {
                if(a[0]=="OFFLINE") return true;
                else return false;
            }
            else return false;
        });

        for (const auto& event : events) {
            // cout<<event[0]<<" "<<event[1]<<" "<<event[2]<<endl;
            string eventType = event[0];
            int timestamp = stoi(event[1]);
            for (int i = 0; i < numberOfUsers; ++i) {
                if (backOnlineTime[i] != -1 && timestamp >= backOnlineTime[i]) {
                    isOnline[i] = true;
                    backOnlineTime[i] = -1;
                }
            }

            if (eventType == "OFFLINE") {
                int userId = stoi(event[2]);
                isOnline[userId] = false;
                backOnlineTime[userId] = timestamp + 60;
            } else if (eventType == "MESSAGE") {
                string mentionsString = event[2];

                if (mentionsString == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentions[i]++;
                    }
                } else if (mentionsString == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (isOnline[i]) {
                            mentions[i]++;
                        }
                    }
                } else {
                    stringstream ss(mentionsString);
                    string token;

                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};
