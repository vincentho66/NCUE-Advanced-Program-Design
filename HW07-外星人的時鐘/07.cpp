#include <bits/stdc++.h>
using namespace std;

struct time {
    int hour;
    int min;
    int sec;
};

struct time E(struct time t) {
    struct time out;
    int allSec = t.hour * 60 * 60 + t.min * 60 + t.sec;
    int tmp;
    out.sec = allSec % 30;
    allSec /= 30;
    out.min = allSec % 48;
    allSec /= 48;
    out.hour = allSec;
    return out;
}

struct time Z(struct time t) {
    struct time out;
    int allSec = t.hour * 48 * 30 + t.min * 30 + t.sec;
    int tmp;
    out.sec = allSec % 60;
    allSec /= 60;
    out.min = allSec % 60;
    allSec /= 60;
    out.hour = allSec;
    return out;
}

int main() {
    int n;
    while(cin >> n) {
        while(n--) {
            char c;
            struct time tIn;
            struct time tOut;
            cin >> c;
            cin >> tIn.hour >> tIn.min >> tIn.sec;
            if(c == 'E') {
                tOut = E(tIn);
                cout << "Z " << tOut.hour << " " << tOut.min << " " << tOut.sec << endl;
            }
            else if(c == 'Z') {
                tOut = Z(tIn);
                cout << "E " << tOut.hour << " " << tOut.min << " " << tOut.sec << endl;
            }
        }
    }
    return 0;
}