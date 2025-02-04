class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int flips = 0;
        int flipcountfrompastfori = 0;
        vector<bool> isFlipped(n, false);
        for (int i = 0; i < n; i++) {
            if (i - k >= 0 and isFlipped[i - k] == true) { // abhi isFlipped[i-k] valla ith index par impack nahi bana raha hoga to usko minus karaegae
                flipcountfrompastfori--;
            }
            if (flipcountfrompastfori % 2 == nums[i]) {
                //  we need to flip
                if (i + k > n)
                    return -1;

                flipcountfrompastfori++;
                flips++;
                isFlipped[i] = true;
            }
        }
        return flips;
    }
};

// Approach 2
// similar to 1 st approach but we are not taking any extra spce to marked the flipped bits
class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int flips = 0;
        int flipcountfrompastfori = 0;
        // vector<bool> isFlipped(n,false);
        for (int i = 0; i < n; i++) {
            if (i - k >= 0 and nums[i - k] == -1) { // abhi isFlipped[i-k] valla ith index par impack nahi bana raha hoga to usko minus karaegae
                flipcountfrompastfori--;
            }
            if (flipcountfrompastfori % 2 == nums[i]) {
                //  we need to flip
                if (i + k > n)
                    return -1;

                flipcountfrompastfori++;
                flips++;
                // isFlipped[i]=true;
                nums[i] = -1; // here -1 means we have flipped that particular bit
            }
        }
        return flips;
    }
};

// Approach 3
// TC=O(n)
// SC=O(k)
class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int flips = 0;
        deque<int> isFlipped;
        int flipcountfrompastfori = 0;
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) { // abhi isFlipped[i-k] valla ith index par impack nahi bana raha hoga to usko minus karaegae
                flipcountfrompastfori -= (isFlipped.front());
                isFlipped.pop_front();
            }
            if (flipcountfrompastfori % 2 == nums[i]) {
                //  we need to flip
                if (i + k > n)
                    return -1;

                flipcountfrompastfori++;
                flips++;
                isFlipped.push_back(1); // here 1 means we have flipped that particular bit
            } else {
                isFlipped.push_back(0); // here 1 means we have not flipped that particular bit
            }
        }
        return flips;
    }
};

// Also do 3191 question its also vv similar