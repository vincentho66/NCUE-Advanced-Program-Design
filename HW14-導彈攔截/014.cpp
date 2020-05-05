#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    while(cin >> n) {
        while(n--) {
            int ax = 0, ay = 0, bx = 0, by = 0;
            int mi_amount = 0;
            int tmp;
            cin >> ax >> ay >> bx >> by;
            cin >> mi_amount;
            vector<int> mi_co[mi_amount];
            for (int i = 0; i < mi_amount; ++i) {
                for (int j = 0; j < 2; ++j) {
                    cin >> tmp;
                    mi_co[i].push_back(tmp);
                }
            }
            vector<int> a;
            vector<int> b;
            for (int i = 0; i < mi_amount; ++i) {
                a.push_back((pow(abs(mi_co[i].at(0) - ax), 2) + pow(abs(mi_co[i].at(1) - ay), 2)));
                b.push_back((pow(abs(mi_co[i].at(0) - bx), 2) + pow(abs(mi_co[i].at(1) - by), 2)));
                mi_co[i].clear();
            }
            vector<int> min;
            int max = 0;
            for (int i = 0; i < mi_amount; ++i) {
                max = 0;
                for (int j = 0; j < mi_amount; ++j) {
                    if(a.at(i) < a.at(j)) {
                        if(b.at(j) > max)
                            max = b.at(j);
                    }
                }
                min.push_back(a.at(i) + max);
            }
            for (int i = 0; i < mi_amount; ++i) {
                max = 0;
                for (int j = 0; j < mi_amount; ++j) {
                    if(b.at(i) < b.at(j)) {
                        if(a.at(j) > max)
                            max = a.at(j);
                    }
                }
                min.push_back(b.at(i) + max);
            }
            vector<int>::iterator min_it = min_element(min.begin(), min.end());
            cout << *min_it << endl;
            min.clear();
            a.clear();
            b.clear();
        }
    }
    return 0;
}