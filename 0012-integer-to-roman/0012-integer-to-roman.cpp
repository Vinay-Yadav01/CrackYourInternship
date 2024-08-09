class Solution {
public:
    string intToRoman(int num) {
        // Pairs of Roman numeral symbols and their corresponding integer values
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string ans = "";
        
        for (auto &[value, symbol] : values) {
            // While num is larger than or equal to the value
            while (num >= value) {
                ans += symbol;  // Append the symbol to the result
                num -= value;   // Subtract the value from num
            }
        }
        
        return ans;
    }
};
