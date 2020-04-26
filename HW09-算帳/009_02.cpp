#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct product {
    int price;
    int quantity;
};

int main() {
    map<string, product> m;
    product input;
    string s;
    while(cin >> s) {
        if(s.compare("0000000000") != 0) {
            cin >> input.price >> input.quantity;
            map<string, product>::iterator it1 = m.begin();
            it1 = m.find(s);
            if(it1 != m.end()) {
                input.quantity += it1->second.quantity;
                m[s] = input;
            }
            else
                m[s] = input;
            continue;
        }
        ll total = 0;
        for(auto& it2 : m) {
            if(it2.first[0] == 'X') 
                total += it2.second.price * (it2.second.quantity / 2 + it2.second.quantity % 2);
            else if(it2.first[0] == 'Y')
                total += it2.second.price * (it2.second.quantity - (it2.second.quantity % 2)) * 0.75
                        + it2.second.price * (it2.second.quantity % 2);
            else
                total += it2.second.price * it2.second.quantity;
        }
        cout << total << endl;
        m.clear();
    }
    return 0;
}