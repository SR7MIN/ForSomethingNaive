#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.size();
        if (l == 0) {
            return 0;
        }
        vector<int> next(l);
        getNext(needle, next);
        int i = 0, j = 0;
        int ll = haystack.size();
        while (i < ll && j < l) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == l) {
            return i - j;
        } else {
            return -1;
        }
    }
private:
    void getNext(const string& needle, vector<int>& next) {
        int l = needle.size();
        int j = 0, k = -1;
        next[j] = k;
        while (j < l - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                k++;
                j++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
};
