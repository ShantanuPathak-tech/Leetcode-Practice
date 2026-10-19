class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //T.C = O(N^2)
        // int n = s.length();
        // int m = t.length();
        // if(n != m) return false;
        // for(int i = 0; i < n;i++){
        //     for(int j = i+1;j< m;j++){
        //         if(s[i] == s[j] && t[i] != t[j]) return false;
        //         if(s[i] != s[j] && t[i] == t[j]) return false;
        //     }
        // }
        // return true;

        // Better approach using map
        // if (s.length() != t.length())
        //     return false;
        // unordered_map<char, char> mapS, mapT;
        // for (int i = 0; i < s.length(); ++i) {
        //     char cs = s[i], ct = t[i];
        //     if (mapS.count(cs) && mapS[cs] != ct)
        //         return false;
        //     if (mapT.count(ct) && mapT[ct] != cs)
        //         return false;

        //     mapS[cs] = ct;
        //     mapT[ct] = cs;
        // }
        // return true;

        // Optimal approach
        //T.C = O(N) S.C = O(2N)
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> mp;
        set<char> usedChar;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i])
                    return false;
            } else {
                if (usedChar.find(t[i]) != usedChar.end())
                    return false;
                mp[s[i]] = t[i];
                usedChar.insert(t[i]);
            }
        }
        return true;
    }
};