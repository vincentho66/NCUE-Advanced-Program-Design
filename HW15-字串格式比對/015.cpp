#include <bits/stdc++.h>
using namespace std;

struct present {
    string s;
    char sign;
};

int main() {
    char input;
    present presentIn;
    vector<present> v;
    while(cin.get(input)) {
        if(input == 'a' || input == 'b') {
            presentIn.s.push_back(input);
            continue;
        } else if(input == '*' || input == 'n') {
            presentIn.sign = input;
            v.push_back(presentIn);
            presentIn.s.clear();
            continue;
        } else if(input == '(' || input == ')') {
            continue;
        }
        int nLen = 0, starLen = 0;
        for(auto x : v) {
            if(x.sign == 'n')
                nLen += x.s.length();
            else if(x.sign == '*')
                starLen += x.s.length();
        }
        int time = 0;
        cin >> time;
        string str;
        while(time--) {
            cin >> str;
            vector<vector<int> > possible;
            int tmp = str.length() - nLen;
            for (int i = 1; tmp >= 0; ++i) {
                tmp = str.length() - nLen * (i + 1);
                if((str.length() - nLen * i) % starLen == 0) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back((str.length() - nLen * i) / starLen);
                    possible.push_back(tmp);
                }
            }
            bool noAns = true;
            for(auto x : possible) {
                string compWith;
                compWith.clear();
                for(auto y : v) {
                    if(y.sign == 'n') {
                        for (int i = 1; i <= x.at(0); ++i) {
                            compWith += y.s;
                        }
                    } else if(y.sign == '*') {
                        for (int i = 1; i <= x.at(1); ++i) {
                            compWith += y.s;
                        }
                    }
                }
                if(compWith == str) {
                    cout << "Y " << x.at(0) << " " << x.at(1) << endl;
                    noAns = false;
                    x.clear();
                    break;
                }
                x.clear();
            }
            if(noAns) {
                cout << "N" << endl;
            }
            str.clear();
        }
        v.clear();
        cin.ignore();
    }
    return 0;
}