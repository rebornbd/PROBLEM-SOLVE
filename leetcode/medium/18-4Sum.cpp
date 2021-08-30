#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        time complexity:
            best  case: O(N^3*logN)
            worst case: O(N^3*logN)
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        int numsLen = nums.size();
        for (int i=0; i<numsLen - 3; i++) {
            for (int j=i+1; j<numsLen - 2; j++) {
                int low = j + 1;
                int high = numsLen - 1;
                
                int twoSum = (target - (nums[i] + nums[j]));
                while (high > low) {
                    long long x = nums[low], y = nums[high];
                    
                    long long sum = (twoSum - (x + y));
                    if (sum == 0) {
                        vector<int> sol{nums[i], nums[j], nums[low], nums[high]};
                        sort(sol.begin(), sol.end());
                        res.insert(sol);

                        while(high > low && nums[low] == nums[low+1]) low++;
                        while(high > low && nums[high] == nums[high-1]) high--;
                        low++, high--;
                    }
                    else if (sum > 0) low++;
                    else high--;
                }
            }
        }

        vector<vector<int>> ans;
        for (set<vector<int>> :: iterator it = res.begin(); it != res.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};

class Solution1 {
public:
    /*
        time complexity:
            best case:  O(N^2)
            worst case: O(N^4)
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        unordered_map<long long, vector<pair<int, int>>> hashMap;
        int numsLen = nums.size();
        for (int i=0; i<numsLen-1; i++) {
            for (int j=i+1; j<numsLen; j++) {
                long long sum = nums[i] + nums[j];
                hashMap[sum].push_back(make_pair(i, j));
            }
        }

        set<vector<int>> ans;
        for (int i=0; i<numsLen-1; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (int j=i+1; j<numsLen; j++) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;

                long long sum = nums[i] + nums[j];
                if (hashMap.find(target - sum) != hashMap.end()) {
                    for (auto p : hashMap[target - sum]) {
                        if (p.first != i && p.first != j && p.second != i && p.second != j) {
                            vector<int> sol{nums[i], nums[j], nums[p.first], nums[p.second]};
                            sort(sol.begin(), sol.end());
                            ans.insert(sol);
                        }
                    }
                }
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
    Solution1 solve1;

    // vector<int> nums = {1,0,-1,0,-2,2};
    // int target = 0;

    // vector<int> nums = {2,2,2,2,2};
    // int target = 8;

    // vector<int> nums = {-3,-1,0,2,4,5};
    // int target = 2;

    vector<int> nums = {-4,-3,-2,-1,0,0,1,2,3,4};
    int target = 0;
    

    vector<vector<int>> res = solve.fourSum(nums, target);
    for (auto ans : res) cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    cout << "count: " <<  res.size() << endl;

    vector<vector<int>> res1 = solve1.fourSum(nums, target);
    for (auto ans : res1) cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    cout << "count: " <<  res1.size() << endl;

    return 0;
}

/*
met-01: O(N^4)
for i[0, n-3)
    for j[i+1, n-2)
        for k[j+1, n-1)
            for l[k+1, n)
                ans = {i, j, k, l}

met-02: O(N^3)
sort(nums)
for i[0, n-3)
    for j[i+1, n-2)
        left = j+1
        right = n - 1
        while(right > left)
            ans = {i, j, left, right}

met-03: BEST-CASE | O(N^2), WORST_CASE | O(N^4)
vector<int, vector<pair<int, int>>> allTwoSum;
for i[0, n-1)
    for j[i+1, n)
        sum = nums[i] + nums[j]
        allTwoSum[sum].push_back({i, j})

for i[0, n-1)
    for j[i+1, n)
        remain = target - (nums[i] - nums[j])
        find allTwoSum[remain]:
            for (auto p : allTwoSum[remain]):
                k = p.first
                l = p.second

                if i != k and i != l and j != k and j != l:
                    ans = {i, j, k, l}
*/