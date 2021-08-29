#include<bits/stdc++.h>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int l = 0,
        r = nums.size() - 1;
    
    if (nums.size() == 0)
        return 0;
    
    int m;
    while (r >= l) {
        m = (l+r)/2;

        if (nums[m] == target)
            return m;
        else if (nums[m] < target)
            l = m + 1;
        else r = m -1;
    }
    return l;
}


int main() {
    vector<int>nums = {1,3,5,6};
    int target = 0;

    int res = searchInsert(nums, target);
    cout << res << endl;

    return 0;
}
