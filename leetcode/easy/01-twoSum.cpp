#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> hasNum;

    if (nums.size() > 0)
        hasNum[nums[0]] = 0;
    for (int i=1; i<nums.size(); i++) {
        int nextNumber = target - nums[i];

        if (hasNum.find(nextNumber) != hasNum.end()) {
            return {hasNum[nextNumber], i};
        }
        hasNum[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = twoSum(nums, target);

    if (res.size() > 0) {
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
