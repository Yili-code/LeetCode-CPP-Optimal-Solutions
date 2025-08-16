class Solution {
public:
    long long specialPalindrome(long long n) {
        vector<long long> candidates;

        // Generate palindromes by constructing half and mirroring
        for (int len = 1; len <= 18; ++len) { // max 18-digit numbers
            int halfLen = (len + 1) / 2;

            // Generate all digit combinations for the first half
            generateHalf(halfLen, "", n, candidates);
        }

        // Find the smallest palindrome >= n that satisfies the frequency condition
        sort(candidates.begin(), candidates.end());
        for (long long x : candidates) {
            if (x >= n && checkFrequency(x)) return x;
        }

        return -1; // should not reach here
    }

private:
    // Generate first half and mirror to full palindrome
    void generateHalf(int len, string cur, long long n, vector<long long>& candidates) {
        if (cur.size() == len) {
            string rev = cur;
            reverse(rev.begin(), rev.end());
            string full = cur + rev.substr(len % 2); // mirror
            candidates.push_back(stoll(full));
            return;
        }

        // Try digits 1–3 (0 cannot start)
        for (char d = '1'; d <= '3'; ++d) {
            generateHalf(len, cur + d, n, candidates);
        }
    }

    // Check if each digit appears exactly as its value
    bool checkFrequency(long long x) {
        string s = to_string(x);
        int freq[10] = {0};
        for (char c : s) freq[c - '0']++;
        for (int d = 0; d <= 9; ++d) {
            if (freq[d] && freq[d] != d) return false;
        }
        return true;
    }
};
