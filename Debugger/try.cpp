// Date Created :
// Date Completed :

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
bool isPossible(string &s, string &t) {
    // code here
    int i = 0, j = 0;
    int n = s.length();
    int m = t.length();
    int ch = s[0];
    while (i < n and s[i] == ch) {
        i++;
    }

    while (j < m and t[j] == ch) {
        j++;
    }

    cout << i << " " << j;
    if (i != j)
        return false;
    while (i < n and j < m) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    if (i >= n)
        return true;
    return false;
}
int main() {
    string s = "abc";
    string t = "aabbcc";
    cout << isPossible(s, t);
    return 0;
}