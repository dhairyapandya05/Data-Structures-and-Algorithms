// Boyer-Moore Voting Algorithm

vector<int> majorityElement(vector<int> &v) {
    int n = v.size();
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int ele1 = 0, ele2 = 0; // No need for INT_MIN

    for (int it : v) {
        if (cnt1 == 0 && it != ele2) {
            ele1 = it;
            cnt1 = 1;
        } else if (cnt2 == 0 && it != ele1) {
            ele2 = it;
            cnt2 = 1;
        } else if (it == ele1) {
            cnt1++;
        } else if (it == ele2) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    int hash1 = 0, hash2 = 0;
    for (int it : v) {
        if (it == ele1)
            hash1++;
        else if (it == ele2)
            hash2++; // Avoids redundant check when it == ele1
    }

    int threshold = n / 3; // No need for ceil()
    if (hash1 > threshold)
        ans.push_back(ele1);
    if (hash2 > threshold)
        ans.push_back(ele2);

    sort(ans.begin(), ans.end());
    return ans;
}
// prefixXOR[i]=prefixXOR[j]⊕b
// prefixXOR[j]=prefixXOR[i]⊕b

// Technique 2
// Hashing
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    mp.reserve(nums.size()); // Prevents rehashing overhead

    for (int i = 0, n = nums.size(); i < n; i++) {
        if (auto it = mp.find(target - nums[i]); it != mp.end()) {
            return {it->second, i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

// Technique 3
