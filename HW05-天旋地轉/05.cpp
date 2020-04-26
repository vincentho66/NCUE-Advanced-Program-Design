#include <bits/stdc++.h>
using namespace std;

int main() {
    int r = 0, c = 0, n = 0;
    while(cin >> r >> c >> n) {
        vector<int> matrix[r];
        vector<int> flip(c);
        int temp = 0;
        for (int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                //cin >> matrix[i][j];
                matrix[i].push_back(temp);
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            flip.push_back(temp);
        }
        //reverse(matrix.begin(),matrix.end());
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                cout << matrix[i].at(j) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}