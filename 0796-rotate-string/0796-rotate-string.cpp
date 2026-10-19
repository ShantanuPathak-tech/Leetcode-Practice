class Solution {
public:
    bool rotateString(string s, string goal) {
        //T.C = O(N^2), S.C = O(N)
        if (s.size() != goal.size())
            return false;
        s += s;// double the string so all possible substring are present
        int m = goal.size();
        int n = s.size();

        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != goal[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }
        return false;
    }
};