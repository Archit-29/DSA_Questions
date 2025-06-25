class Solution {
public:
    void fillLps(vector<int>& lps, const string& needle) {
        int len = 0;
        int i = 1;
        int m = needle.size();
        lps[0] = 0;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m);
        fillLps(lps, needle);

        int i = 0, j = 0;

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
            if (j == m) {
                return i - j;
            }
        }
        return -1;
    }
};