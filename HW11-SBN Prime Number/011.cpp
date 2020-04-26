#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

bool isPrime(ui input) {
	if(input == 1)
        return false;
    else {
		for(ui i = 2; i <= sqrt(input); ++i) {
            if(input % i == 0)
				return false;
		}
	}
	return true;
}

ui toBinary(ui input) {
    ui count = 0;
    while(input != 0) {
        count += input % 2;
        input /= 2;
    }
    return count;
}

int main() {
    ui input = 0;
    while(cin >> input && input != 0) {
        ui temp = input;
        while(temp) {
            if(isPrime(temp)) {
                if(toBinary(input) == toBinary(temp)) {
                    cout << temp << endl;
                    break;
                }
                else {
                    temp--;
                    continue;
                }
            }
            else {
                temp--;
                continue;
            } 
        }
        if(temp == 0)
            cout << 0 << endl;
    }
    return 0;
}