#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<vector<int>> line(n);
        int tmp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> tmp;
                line[i].push_back(tmp);
            }
        }
        sort(line.begin(), line.end());
        int line_begin = line[0].at(0), line_end = line[1].at(0);
        int tmp_length = line_end - line_begin, total_length = 0;
        for (int i = 1; i < line.size(); i++) {
            if(line[0].at(i) == line_begin) {
                line_end = line[1].at(i);
                tmp_length = line_end - line_begin;
                if(line[0].at(i) == line[0].back()) {
                    total_length += tmp_length;
                    break;
                }
                else if(line[0].at(i+1) != line[0].at(i)) {
                    total_length += tmp_length;
                    line_begin = line_end;
                }
            }
            else {

            }
        }
    }
    return 0;
}