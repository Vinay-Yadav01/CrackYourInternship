class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";  // Start with initial string "a"
        
        // Continue appending transformed string until word's length is at least k
        while (word.size() < k) {
            string nextPart = "";  // The part that will be appended to word
            
            // Generate the next characters by shifting each character in word by 1
            for (char ch : word) {
                if (ch == 'z') {
                    nextPart += 'a';  // 'z' rolls over to 'a'
                } else {
                    nextPart += (ch + 1);  // Other characters are incremented
                }
            }
            
            // Append the new part to word
            word += nextPart;
        }
        
        // Return the k-th character (1-indexed, so we use k-1 for 0-indexed string)
        return word[k - 1];
    }
};