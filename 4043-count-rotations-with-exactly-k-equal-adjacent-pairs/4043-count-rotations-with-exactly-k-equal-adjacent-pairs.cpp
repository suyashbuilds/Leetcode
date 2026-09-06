#include <string>

class Solution {
public:
    int countRotations(std::string s, int k) {
        int n = s.length();
        if (n <= 1) {
            return (k == 0) ? 1 : 0;
        }

        int currentMatches = 0;
        int rotationCount = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                currentMatches++;
            }
        }

        if (currentMatches == k) {
            rotationCount++;
        }

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                currentMatches--;
            }

            int prevIdx = (i + n - 2) % n;
            int newIdx = (i + n - 1) % n;
            if (s[prevIdx] == s[newIdx]) {
                currentMatches++;
            }

            if (currentMatches == k) {
                rotationCount++;
            }
        }

        return rotationCount;
    }
};
