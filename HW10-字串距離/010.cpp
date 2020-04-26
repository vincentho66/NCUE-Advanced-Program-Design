#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        while(n--) {
            string s1, s2;
            int count = 0;
            cin >> s1 >> s2;
            for (int i = 0; i < s1.length(); ++i) {
                count += abs((int)s1[i] - (int)s2[i]);
            }
            cout << count << endl;
        }
    }
    return 0;
}