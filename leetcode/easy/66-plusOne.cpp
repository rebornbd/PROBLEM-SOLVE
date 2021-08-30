#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int digitLen = digits.size() - 1;

    int c = 0, n = 0;
    vector<int> res;
    for (int i = 0; i <= digitLen; i++) {
        if (i == 0) {
            n = (digits[digitLen - i] + 1);
            c = n / 10;
        }
        else {
            n = digits[digitLen - i] + c;
            c = n / 10;
        }
        res.push_back(n % 10);
    }
    if (c) res.push_back(c);

    vector<int> ans;
    int resLen = res.size() - 1;
    for (int i = 0; i <= resLen; i++) {
        ans.push_back(res[resLen - i]);
    }
    return ans;
}

int main() {
    vector<int> digits = {9, 9, 9};
    // vector<int> digits = {9};

    vector<int> res = plusOne(digits);
    for (auto d : res)
        cout << d << " ";
    
    return 0;
}
