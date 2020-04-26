#include <bits/stdc++.h>
using namespace std;

double x_count = 0, y_count = 0;

void cal(double x, double y, double width, double time) {
    if(x > 0 && y > 0) {
        ::x_count += x;
        ::y_count += y;
    }
    if(time == 0)
        return;
    cal(x + (width / 2), y + (width / 2), width / 2, time - 1);
    cal(x - (width / 2), y + (width / 2), width / 2, time - 1);
    cal(x - (width / 2), y - (width / 2), width / 2, time - 1);
    cal(x + (width / 2), y - (width / 2), width / 2, time - 1);
}

int main() {
    double x = 0, y = 0, width = 0, time = 0;
    while(cin >> x >> y >> width >> time) {
        cal(x + (width / 2), y + (width / 2), width / 2, time);
        cal(x - (width / 2), y + (width / 2), width / 2, time);
        cal(x - (width / 2), y - (width / 2), width / 2, time);
        cal(x + (width / 2), y - (width / 2), width / 2, time);
        cout << ::x_count << " " << ::y_count << endl;
        ::x_count = 0;
        ::y_count = 0;
    }
    return 0;
}