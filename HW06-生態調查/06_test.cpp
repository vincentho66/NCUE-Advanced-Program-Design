#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        string animal[100];
        string place[100];
        int amount[100];
        int index = 0;
        while(n--) {
            string animal_temp;
            string place_temp;
            int amount_temp;
            cin >> animal_temp >> amount_temp >> place_temp;
            vector<int> v;
            int contain_index = -1;
            for (int i = 0; i <= index; i++) {
                if(animal[i] == animal_temp)
                    v.push_back(i);
            }
            for (int i = 0; i <= index; i++) {
                if(place[i] == place_temp) {
                    for(int j = 0; j < v.size(); j++) {
                        if(v.at(j) == i) {
                            contain_index = i;
                            break;
                        }
                    }
                }
            }
            if(contain_index != -1)
                amount[contain_index] += amount_temp;
            else {
                animal[index] = animal_temp;
                place[index] = place_temp;
                amount[index] = amount_temp;
                index++;
            }
        }
        vector<string> v;
        for (int i = 0; i < index; i++) {
            bool place_chk = true;
            if(i == 0)
                v.push_back(place[i]);
            else {
                for(int k = 0; k < v.size(); k++) {
                    if(v.at(k) == place[i]) {
                        place_chk = false;
                        break;
                    }
                }
                if(place_chk)
                    v.push_back(place[i]);
            }
            if(place_chk) {
                cout << place[i] << " : ";
                int f = 0;
                for (int j = 0; j < index; j++) {
                    if(place[i] == place[j]) {
                        if(f == 0) {
                            cout << animal[j] << " " << amount[j];
                            f++;
                        }
                        else
                            cout << ", " << animal[j] << " " << amount[j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}