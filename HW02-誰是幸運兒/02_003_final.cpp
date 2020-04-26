#include <bits/stdc++.h>
using namespace std;

int luckyNumber(int, int, int);

int main() {
    int n = 0, m = 0, k = 0;            //n: people number, m: boom number, k: times
    while(cin >> n >> m >> k) {
        if(k == 0)
            cout << "1" << endl;
        else
            cout << luckyNumber(n, m, k) + 1 << endl;   //return to origin number
    }
    return 0;
}

int luckyNumber(int n, int m, int k) {          //renumber when explode
    if(k == 1)
        return m % n;
    else
        return (luckyNumber(n - 1, m, k - 1) + m) % n;
}