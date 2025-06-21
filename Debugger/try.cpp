#include <bits/stdc++.h>
using namespace std;

int check(vector<int> nums, int evenflag) {
    int count = 0;
    for (auto it : nums) {
        if ((evenflag == 1 and it % 2 == 1)) {
            count++;
        } else if (evenflag == 0 and it % 2 == 0) {
            count++;
        }
        evenflag = 1 - evenflag;
    }
    return count;
}
int minSwaps(vector<int> &nums) {
    int n = nums.size();
    int even = 0;
    int odd = 0;
    for (auto it : nums) {
        if (it % 2 == 0)
            even++;
        else
            odd++;
    }
    if (!(abs(even - odd) <= 1))
        return -1;
    int ans = -1;
    cout << "We are here: " << endl
         << "Odd: " << odd << endl
         << "Even: " << even << endl;
    if (even > odd) {
        ans = check(nums, 1);
    } else if (even < odd) {
        ans = check(nums, 0);
    } else {
        int temp = check(nums, 1);
        ans = min(temp, n - temp);
    }

    return ans;
}

int main() {
    vector<int> temp = {2, 4, 6, 5, 7};
    int ans = minSwaps(temp);

    cout << "Answer: " << ans << endl;
    return 0;
}
