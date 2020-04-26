#include <bits/stdc++.h>
using namespace std;

int main() {
    string place, animal;
    int amount;
    int n;
    while(cin >> n) {
        vector<vector<string>> list(n);             //place -> animal
        vector<int> amountVec(n);
        while(n--) {
            cin >> animal >> amount >> place;
            for (int i = 0; i < list.size(); i++) {
                if(place.compare(list[i].at(0)) == 0) {
                    if(animal.compare(list[i].at(1)) == 0) {        //all equal
                        amountVec.at(i) += amount;
                    }
                    else {                                          //place equal

                    }
                }
            }
        }
    }
    return 0;
}