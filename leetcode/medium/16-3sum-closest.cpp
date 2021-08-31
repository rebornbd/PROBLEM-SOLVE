#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int numsLen = nums.size();
        int res = INT_MAX - 1000;
        for (int i=0; i<numsLen-2; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            int low = i + 1;
            int high = numsLen - 1;
            while (high > low) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if (sum == target) {
                    return sum;
                }
                else if (sum < target) low++;
                else high--;

                int prevDist = abs(target - res);
                int curtDist = abs(target - sum);
                if (prevDist > curtDist) {
                    res = sum;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution solve;

    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    int res = solve.threeSumClosest(nums, target);
    cout << res << endl;

    return 0;
}