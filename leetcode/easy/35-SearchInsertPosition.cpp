#include<bits/stdc++.h>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int l = 0,
        r = nums.size() - 1,
        m = 0;

    if (nums.size() == 0)
        return 0;
    
    while (true) {
        m = (l+r)/2;

        if (nums[m] == target)
            return m;
        else if (nums[m] < target)
            l = m + 1;
        else r = m -1;

        if (!(r >= l)) {
            if (nums[m] < target)
                return m + 1;
            return m;
        }
    }

}


int main() {
    vector<int>nums = {1,3,5,6};
    int target = 0;

    int res = searchInsert(nums, target);
    cout << res << endl;

    return 0;
}
