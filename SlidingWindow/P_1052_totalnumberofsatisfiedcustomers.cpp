// https://leetcode.com/problems/grumpy-bookstore-owner/?envType=daily-question&envId=2024-06-21
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int currentgrumpycust = 0;
        for (int i = 0; i < minutes; i++) {
            currentgrumpycust += customers[i] * grumpy[i];
        }
        int i = 0;
        int j = minutes;
        int maxcustomers =
            currentgrumpycust; // abhi kae liyae suppose  kiya hai humnae
        while (j < customers.size()) {
            currentgrumpycust += customers[j] * grumpy[j];
            currentgrumpycust -= customers[i] * grumpy[i];
            maxcustomers = max(maxcustomers, currentgrumpycust);
            i++;
            j++;
        }
        int alreadygrumpy = 0;
        // also check for already grumpy
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                alreadygrumpy += customers[i];
        }
        return alreadygrumpy + maxcustomers;
    }
};