class Solution {
public:
    string losingPlayer(int x, int y) {
        string winner = "Bob";

        while (x >= 0 or y >= 0) {
            x -= 1;
            y -= 4;
            if (x < 0 or y < 0) {
                break;
            }
            winner = (winner == "Alice") ? "Bob" : "Alice";
        }
        return winner;
    }
};