class Solution {
public:
    int minLength(string s) {
        string part1 = "AB";
        string part2 = "CD";
        while((s.find(part1)<s.length()) || (s.find(part2)<s.length())){
            if(s.find(part1)<s.length()) s.erase(s.find(part1), 2);
            else s.erase(s.find(part2),2);
        }
        return s.length();
    }
};