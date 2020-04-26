#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, r = 0, c = 0, tmp = 0;        //r: 列, c: 行
    cin >> n;
    while(n--) {
        cin >> r >> c;
        vector<int> cargoC(c, 0);
        vector<int> cargoR(r, 0);
        for (unsigned int i = 0; i < r; i++) {
            for (unsigned int j = 0; j < c; j++) {
                cin >> tmp;
                cargoR.at(i) += tmp;
                cargoC.at(j) += tmp;
            }
        }
        int ansR = 0, ansC = 0;
        long long totalCost_R = 9000000000000000000, totalCost_C = 9000000000000000000, cost = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < r; j++) {
                cost += abs(j - i) * cargoR.at(j);
            }
            if(cost < totalCost_R) {
                totalCost_R = cost;
                ansR = i;
            }
            cost = 0;
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                cost += abs(j - i) * cargoC.at(j);
            }
            if(cost < totalCost_C) {
                totalCost_C = cost;
                ansC = i;
            }
            cost = 0;
        }
        cout << ansR + 1 << " " << ansC + 1 << " " <<
            (totalCost_R + totalCost_C) * 10 << endl;
        cargoR.clear();
        cargoC.clear(); 
    }
    return 0;
}