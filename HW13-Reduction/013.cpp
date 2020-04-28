#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    while(cin >> n) {
        while(n--) {
            int input = 0;
            vector<int> number;
            cin >> m;
            for (int i = 0; i < m; i++) {
                cin >> input;
                number.push_back(input);
            }
            //cout << "check point" << endl;
            int numtmp[1000][1000] = {0};
            int numtmp2[1000][1000] = {0};
            int d = 2;
            while (d < m) {
                //cout << "check point" << endl;
                for (int i = 1, j = i + d; i <= m, j <= m; i++, j++) {
            	    int big, small, max = 0, min = 1000000000;
                    if (d == 2) {
                        //cout << "check point" << endl;
                        numtmp[i][j] = number[i - 1] * number[i] * number[j - 1];
                        numtmp2[i][j] = number[i - 1] * number[i] * number[j - 1];
                    }
                    else {
                        for (int k = i + 1; k < j; k++) {
                            big = numtmp[i][k] + numtmp[k][j] + number[i - 1] * number[k - 1] * number[j - 1];
                            small = numtmp2[i][k] + numtmp2[k][j] + number[i - 1] * number[k - 1] * number[j - 1];
                            if (big > max)
                                max = big;
                            if (small < min)
                                min = small;
                        }
                        numtmp[i][j] = max;
                        numtmp2[i][j] = min;
                    }
                }
                d++;
                //cout << d << endl;
            }
            //cout << "check point" << endl;
            cout << numtmp[1][m] << " " << numtmp2[1][m] << endl;
            number.clear();
        }
    }
    return 0;
}