#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        int numsLen = nums.size();
        int i, j, l, r;
        for (i=1; i<numsLen - 2; i++) {
            for (j=i+1; j<numsLen - 1; j++) {
                l = 0, r = numsLen - 1;

                while (r > l) {
                    int sum = (target - (nums[i] + nums[j] + nums[l] + nums[r]));

                    if (sum == 0) {
                        vector<int> sol{nums[i], nums[j], nums[l], nums[r]};
                        sort(sol.begin(), sol.end());

                        res.insert(sol);

                        // if (i != l && i != r && j != l && j != r) {
                        //     vector<int> sol{nums[i], nums[j], nums[l], nums[r]};
                        //     sort(sol.begin(), sol.end());

                        //     res.insert(sol);
                        // }
                    }
                    else if (sum < 0) l += 1;
                    else r -= 1;
                }

                // for (x=j+1; x<numsLen - 1; x++) {
                //     for (y=x+1; y<numsLen; y++) {
                //         if ((nums[i] + nums[j] + nums[x] + nums[y]) == target) {
                //             vector<int> sol{nums[i], nums[j], nums[x], nums[y]};
                //             sort(sol.begin(), sol.end());

                //             res.insert(sol);
                //         }
                //     }
                // }
            }
        }

        vector<vector<int>> ans;
        for (set<vector<int>> :: iterator it = res.begin(); it != res.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};

int main() {
    Solution solve;

    // vector<int> nums = {1,0,-1,0,-2,2};
    // int target = 0;

    vector<int> nums = {2,2,2,2,2};
    int target = 8;

    // vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    //                     21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
    //                     41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
    //                     61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
    //                     81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 
    //                     101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    //                     121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 
    //                     141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 
    //                     161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 
    //                     181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199};
    // int target = 110;

    vector<vector<int>> res = solve.fourSum(nums, target);
    cout << res.size() << endl;
    // for (auto ans : res) {
    //     cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    // }
    // for (int i=0; i<res.size(); i++){
    //     cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << endl;
    // }

    return 0;
}