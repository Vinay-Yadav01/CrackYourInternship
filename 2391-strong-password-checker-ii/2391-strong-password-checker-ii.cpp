class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int size = password.size();
        if (size < 8)
            return false;
        bool lowerCase = false, upperCase = false, number = false,
             spChar = false;
        for (int i = 0; i < size; i++) {
            if (isdigit(password[i]))
                number = true;
            else if (islower(password[i]))
                lowerCase = true;
            else if (isupper(password[i]))
                upperCase = true;
            else
                spChar = true;
            if (i + 1 < size && password[i] == password[i + 1])
                return false;
        }
        return lowerCase && upperCase && number && spChar;
    }
};