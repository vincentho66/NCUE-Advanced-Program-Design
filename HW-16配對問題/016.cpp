#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int> > student;
    vector<vector<int> > professor;
    vector<int> tmp;
    int input;
    char dump;
    for(int i = 0; i < 10; ++i) {
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> dump;
        for(int j = 0; j < 11; ++j) {
            cin >> input;
            cin.ignore();
            tmp.push_back(input);
        }
        student.push_back(tmp);
        tmp.clear();
    }
    for(int i = 0; i < 10; ++i) {
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> dump;
        for(int j = 0; j < 11; ++j) {
            cin >> input;
            cin.ignore();
            tmp.push_back(input);
        }
        professor.push_back(tmp);
        tmp.clear();
    }
    for (int j = 1; j < 11; j++) {
		for (int i = 0; i < 10; i++) {
			int pro, min = 11, stu[10] = {0}, hope, match, memory = 0, temp = 0; // 5,5,6,10,6,5,10,7,3,6
        	
			if (student[i][j]) {
				for (int x = i; x < 10; x++) {
					pro = student[x][j];
					if (pro) { // 同行研究生比較選到的教授 
						memory = 1; // 若選到一樣教授就做記號 
						temp = j;
						//cout << pro << " ";
						break;
					}
				}
				for (int x = 0; x < 10; x++) {
					if (student[x][temp] == pro) {
						stu[x] = student[x][0]; // 選到一樣教授的研究生編號儲存成 stu陣列 
						//cout << stu[x] << " ";
					}	
				}
				for (int x = 0; x < 10; x++) {
					for (int y = 1; y < 11; y++) {
						if (professor[pro - 1][y] == stu[x]) { // 研究生編號對應到教授志願 
							hope = y; // 研究生在教授志願的第 y個 
							if (hope < min) {
								min = hope; // 最前面的志願選到該教授 
								match = x;
							}
						}	
					}
				}
				for (int y = 1; y < 11; y++) {
					for (int x = 0; x < 10; x++) {
						if (student[x][y] == pro) { // 若陣列裡有被選走的教授就清為 0 
							student[x][y] = 0;
						}
					}
				}
				for (int y = 2; y < 11; y++)
					student[match][y] = 0;
				student[match][1] = pro;	
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << "A" << i + 1 << ",B" << student[i][1] << endl;
    return 0;
}