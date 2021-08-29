#include<bits/stdc++.h>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    
    sort(nums.begin(), nums.end());

    int k = 0;
    for (int i=1; i<nums.size(); i++) {
        if (nums[k] != nums[i]) {
            k++;
            nums[k] = nums[i];
        }
    }

    return (k+1);
}

int main() {
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};

    int res = removeDuplicates(nums);
    cout << res << endl;

    return 0;
}
