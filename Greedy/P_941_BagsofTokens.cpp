class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n - 1;
        int score = 0;
        int maxscore = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                score++;
                power -= tokens[i];
                i++;
                maxscore = max(maxscore, score);

            } else if (score > 0) {
                score--;
                power += tokens[j];
                j--;
            }
            else{
                break;
            }
        }
        return maxscore;
    }
};