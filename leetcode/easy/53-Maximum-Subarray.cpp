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

int main() {
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums = {-2, -1, -3, -4, -1, -2, -1, -5, -4};

    int maxSum = maxSubArray(nums);
    cout << maxSum << endl;

    return 0;
}
