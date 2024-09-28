class Solution {
public:
    int solve(int i, vector<int>& heights, int bricks, int ladders, int n) {
        if (i == n - 1) {
            return 0;
        }

        if (heights[i] >= heights[i + 1]) {
            return 1 + solve(i + 1, heights, bricks, ladders, n);
        }
        // the height odf the next building is more than the curent building
        else {
            int ans1 = 0;
            if (ladders > 0) {
                ans1 = 1 + solve(i + 1, heights, bricks, ladders - 1,
                                 n); // use the ladder
            }

            int ans2 = 0;
            if (bricks >= heights[i + 1] - heights[i]) {
                int heightdiff = heights[i + 1] - heights[i];
                ans2 = 1 + solve(i + 1, heights, bricks - heightdiff, ladders,
                                 n); // use the bricks
            }

            return max(ans1, ans2);
        }
        return -1;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int idx = 0;
        int n = heights.size();
        return solve(idx, heights, bricks, ladders, n);
    }
};

// We aill use here lazy greedy
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        int i = 0;
        for (; i < n - 1; i++) {
            if (heights[i] >= heights[i + 1]) {
                continue;
            } else {
                int bricksreq = heights[i + 1] - heights[i];
                if (bricks >= bricksreq) {
                    pq.push(bricksreq);
                    bricks -= bricksreq;
                } else if (ladders > 0) {
                    
                    if (!pq.empty()) {
                        int maxpastbricks = pq.top();
                        if (bricksreq <= maxpastbricks) {
                            pq.pop();
                            bricks += maxpastbricks;
                            bricks -= bricksreq;
                            pq.push(bricksreq);
                            ladders--;
                        } else {
                            ladders--;
                        }
                    }
                    else{
                        ladders--;
                    }

                } else {
                    break;
                }
            }
        }
        return i;
    }
};