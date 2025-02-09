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

// Approach-2 (Using frequency of skills similar to counting sort)
// T.C : O(n)
// S.C : O(1000) ~= O(1)
class Solution {
public:
    long long dividePlayers(vector<int> &skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int SUM = 0;
        for (int &s : skill) {
            SUM += s;
            vec[s]++; // freq updated
        }

        int teams = n / 2;

        if (SUM % teams != 0) {
            return -1;
        }

        int target = SUM / teams;
        long long chem = 0;

        for (int i = 0; i < n; i++) {
            int currSkill = skill[i];
            int remainSkill = target - currSkill;

            if (vec[remainSkill] <= 0) {
                return -1;
            }

            chem += (long long)currSkill * (long long)(remainSkill);
            vec[remainSkill] -= 1;
        }

        return chem / 2;
    }
};
