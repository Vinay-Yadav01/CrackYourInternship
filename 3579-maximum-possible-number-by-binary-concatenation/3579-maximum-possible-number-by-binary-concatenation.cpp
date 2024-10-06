class Solution {
    string toBinary(int n) {
        string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        return binary == "" ? "0" : binary;
    }
    int binaryToNum(string binary) {
    int num = 0;
    for (char bit : binary) {
        num = num * 2 + (bit - '0');  // Convert character '0'/'1' to int and update the number
    }
    return num;
}

public:
    int maxGoodNumber(vector<int>& nums) {
        string maxi = "";
        int n = nums.size();
        int ans = -1;
                for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // Skip if indices are the same
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue; // Skip if indices are the same

                    // Combine the binary representations of nums[i], nums[j], nums[k]
                    string str = toBinary(nums[i]) + toBinary(nums[j]) + toBinary(nums[k]);

                    // Compare the binary string lexicographically
                    if (str > maxi) {
                        maxi = str;
                        ans = binaryToNum(maxi);  // Convert back to number
                    }
                }
            }
        }
        return ans;
    }
};