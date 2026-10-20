class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                            {'C', 100}, {'D', 500}, {'M', 1000}};

        int i = 0, n = s.size();
        int ans = 0;

        while (i < n) {
            if (i + 1 < n && m[s[i]] < m[s[i + 1]]) {
                ans += m[s[i + 1]] -
                       m[s[i]]; // if the i+1 is > i then add the difference of
                                // avlue of i+1 and i to the ans
                i += 2;
            } else {
                ans +=
                    m[s[i]]; // if i+1 is smaller then simply add the value of i
                i++;
            }
        }
        return ans;
    }
};