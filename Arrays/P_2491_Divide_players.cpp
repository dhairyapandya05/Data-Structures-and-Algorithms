class Solution {
public:
    long long dividePlayers(vector<int> &skill) {
        int n = skill.size();
        long long int sum = accumulate(skill.begin(), skill.end(), 0LL);
        int numberTeam = (n / 2);
        if ((sum % numberTeam) == 1) {
            return -1;
        }
        int teamcontribution = sum / numberTeam;
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = n - 1;
        int team = 0;
        long long ans = 0;
        while (i < j) {
            if (skill[i] + skill[j] == teamcontribution) {
                ans += (skill[i] * skill[j]);
                i++;
                j--;
                team++;
            } else {
                return -1;
            }
        }
        return ans;
    }
};