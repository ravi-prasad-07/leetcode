class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();

        if (n == 1) {
            return s;
        }

        string ans = s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        s = s + '#' + rev;

        int m = s.length();
        vector<int> lps(m, 0);

        int length = 0;
        int i = 1;

        while (i < m) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            }
            else {
                if (length != 0) {
                    length = lps[length - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int idx = lps[m - 1];

        string sub = ans.substr(idx);

        reverse(sub.begin(), sub.end());

        sub += ans;

        return sub;
    }
};
