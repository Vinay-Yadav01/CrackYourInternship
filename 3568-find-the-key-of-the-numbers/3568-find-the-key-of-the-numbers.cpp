class Solution {
    string padToFourDigits(int num) {
    string str = to_string(num);
    while (str.length() < 4) {
        str = "0" + str;
    }
    return str;
}
public:
    int generateKey(int num1, int num2, int num3) {
        // Step 1: Pad the numbers to four digits
    string str1 = padToFourDigits(num1);
    string str2 = padToFourDigits(num2);
    string str3 = padToFourDigits(num3);

    // Step 2: Compare each corresponding digit and find the smallest
    string key = "";
    for (int i = 0; i < 4; ++i) {
        char minDigit = min({str1[i], str2[i], str3[i]});
        key += minDigit;
    }

    // Step 3: Remove leading zeros
    int nonZeroIndex = 0;
    while (nonZeroIndex < key.length() && key[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }

    // If all digits are zeros, return 0
    if (nonZeroIndex == key.length()) {
        return 0;
    }

    // Otherwise, return the key without leading zeros
    return stoi(key.substr(nonZeroIndex));
    }
};