#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // return: nums[i] + nums[j] + nums[k] == 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int numsLen = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<numsLen - 2; i++) {
            if (i == 0 || (nums[i] != nums[i-1])) {
                int low = i + 1;
                int high = numsLen - 1;

                while (high > low) {
                    int sum = nums[i] + nums[low] + nums[high];

                    if (sum == 0) {
                        vector<int> sol{nums[i], nums[low], nums[high]};
                        sort(sol.begin(), sol.end());
                        res.push_back(sol);

                        while(high > low && nums[low] == nums[low+1]) low++;
                        while(high > low && nums[high] == nums[high-1]) high--;
                        low++, high--;
                    }
                    else if (sum < 0) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution solve;

    vector<int> nums = {-1,0,1,2,-1,-4};
    int target = 0;

    vector<vector<int>> res = solve.threeSum(nums);
    cout << res.size() << endl;

    return 0;
}