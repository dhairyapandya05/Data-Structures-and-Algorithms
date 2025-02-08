class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        long long int chalkRequirement =
            accumulate(chalk.begin(), chalk.end(), 0L);
        int remainingChalkRequirementAfterCycles = k % chalkRequirement;
        int i = 0;
        while (remainingChalkRequirementAfterCycles - chalk[i] >= 0) {
            remainingChalkRequirementAfterCycles -= chalk[i];
            i++;
        }
        return i;
    }
};