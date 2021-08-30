#include <bits/stdc++.h>
using namespace std;

#define lli     long long int


int myAtoi(string s) {
    lli res = 0;
    bool whiteSpace = true,
        signNumber = true,
        isNegative = false;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ' && whiteSpace) { continue; }
        else if ((s[i] == '+' || s[i] == '-') && signNumber) {
            if (s[i] == '-') isNegative = true;

            whiteSpace = false; signNumber = false;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            res = (res*10) + (s[i] - '0');
            if (res > INT_MAX) break;

            whiteSpace = false; signNumber = false;
        }
        else break;
    }

    if (isNegative) res *= -1;

    if (res >= INT_MAX) return INT_MAX;
    else if (res <= INT_MIN) return INT_MIN;

    return res;
}

int main() {
    string s = "         -123";

    lli res = myAtoi(s);
    cout << res << endl;
    
    return 0;
}
