/*
    leetcode: 53
    Maximum Sum Subarray
    algo: Kadane's Algorithm
*/
#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int> nums) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int num : nums) {
        max_ending_here += num;
        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

vector<int> maxSubArrayWithValues(vector<int> nums) {
    int ans = INT_MIN;
    int a = 0;

    int startIndex = 0, endIndex = 0, temIndex = 0;
    for (int i=0; i<nums.size(); i++) {
        a += nums[i];

        if (ans < a) {
            ans = a;
            startIndex = temIndex;
            endIndex = i;
        }
        if (a < 0) {
            a = 0;
            temIndex = i + 1;
        }
    }

    return {ans, startIndex, endIndex};
}

int main() {
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums = {-2, -1, -3, -4, -1, -2, -1, -5, -4};


    int maxSum = maxSubArray(nums);
    cout << maxSum << endl;

    vector<int> res = maxSubArrayWithValues(nums);
    cout << "maxsum: " << res[0] << ", startIndex: " << res[1] << ", endIndex: " << res[2] << endl;

    return 0;
}
