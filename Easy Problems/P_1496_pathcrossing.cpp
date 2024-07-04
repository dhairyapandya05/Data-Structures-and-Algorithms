class Solution {
public:
    set<pair<int, int>> st;
    int horizontal = 0;
    int vertical = 0;
    bool updatingCordinates(char ch) {
        if (ch == 'N') {
            vertical++;
        } else if (ch == 'S') {
            vertical--;
        } else if (ch == 'E') {
            horizontal++;
        } else if (ch == 'W') {
            horizontal--;
        }

        if (st.find({horizontal, vertical}) != st.end()) {
            return true;
        } else {
            st.insert({horizontal, vertical});
            return false;
        }
    }
    bool isPathCrossing(string path) {
        st.insert({0, 0});
        for (int i = 0; i < path.size(); i++) {
            if (updatingCordinates(path[i]) == true) {
                return true;
            }
        }
        return false;
    }
};