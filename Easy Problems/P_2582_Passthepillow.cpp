class Solution {
public:
    int passThePillow(int n, int time) {
        while (time >= 0) {
            if(time==0){
                return 1;
            }
            for (int i = 1; i <= n; i++) {
                if (time == 0) {
                    return i;
                }
                time--;

            }
            for (int i = n-1; i > 1; i--) {
                if (time == 0) {
                    return i;
                }
                time--;

            }
        }
        return 0;
    }
};