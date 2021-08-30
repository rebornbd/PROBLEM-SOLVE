#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // return: nums[i] + nums[j] + nums[k] == 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int numCount = count(nums.begin(), nums.end(), 0);
        if (numCount == nums.size()) {
            vector<int> sol{0, 0, 0};
            vector<vector<int>> res;
            res.push_back(sol);

            return res;
        }

        int numsLen = nums.size();
        set<vector<int>> ans;
        for (int i=0; i<numsLen; i++) {
            int l = 0, r = numsLen - 1;
            while(r > l) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    if (i != l && i != r && l != r) {
                        vector<int> sol{nums[i], nums[l], nums[r]};
                        sort(sol.begin(), sol.end());

                        ans.insert(sol);
                    }
                    l += 1;
                    r -= 1;
                }
                else if (sum < 0) l++;
                else r--;
            }
        }

        vector<vector<int>> res;
        for (set<vector<int>> :: iterator it = ans.begin(); it != ans.end(); ++it) {
            res.push_back(*it);
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