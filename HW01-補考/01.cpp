#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> score;
    int loop = 0;
    cin >> loop;
    while(loop--) {
        int tmp_i = '\0';
        char tmp_c = '\0';
        while(cin >> tmp_i) {
            score.push_back(tmp_i);
            //fflush(stdin);
            tmp_c = cin.get();
            if(tmp_c == '\n')           //"\r"
                break;
            else if(tmp_c == ' ')
                continue;
        }
        sort(score.begin(), score.begin() + score.size());
        int scoreAdd = 95 - score.back();
        int paperCount = 0;
        if(scoreAdd > 0) {
            for (vector<int>::iterator it = score.begin(); it != score.end(); it++)
                *it += scoreAdd;
        }
        for (vector<int>::iterator it = score.begin(); it != score.end(); it++) {
            if(*it >= 55 && *it <= 59)
                paperCount++;
        }
        cout << paperCount << endl;
        score.clear();
    }
    return 0;
}