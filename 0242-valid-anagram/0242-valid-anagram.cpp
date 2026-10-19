class Solution {
public:
    bool isAnagram(string s, string t) {
        // Brute force T.C = O(n log n)
        //  if(s.size() != t.size()) return false;
        //  sort(s.begin(), s.end());
        //  sort(t.begin(), t.end());
        //  return s == t;

        // Optimal Approach
        // T.C = O(N), O(1)
        if (s.size() != t.size())
            return false;
        int a[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i])
                return false;
        }
        return true;
    }
};