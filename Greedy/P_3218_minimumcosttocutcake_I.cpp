class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut,
                    vector<int>& verticalCut) {
        int horizontalpieces = 1;
        int verticalpieces = 1;
        int cost = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int i = 0;
        int j = 0;
        while (i < horizontalCut.size() and j < verticalCut.size()) {
            if (horizontalCut[i] > verticalCut[j]) {
                cost += horizontalCut[i] * verticalpieces;
                i++;
                horizontalpieces++;
            } else {
                cost += verticalCut[j] * horizontalpieces;
                j++;
                verticalpieces++;
            }
        }
        while (i < horizontalCut.size()) {
            cost += horizontalCut[i] * verticalpieces;
            i++;
            horizontalpieces++;
        }
        while (j < verticalCut.size()) {
            cost += verticalCut[j] * horizontalpieces;
            j++;
            verticalpieces++;
        }
        return cost;
    }
};