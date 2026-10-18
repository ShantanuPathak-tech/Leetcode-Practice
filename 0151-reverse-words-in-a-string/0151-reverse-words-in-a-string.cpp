class Solution {
public:
    string reverseWords(string s) {
        //Better Aprroach
        //T.C = O(n), S.C = O(n)
        // vector<string> words;
        // int n = s.size(), i = 0;
        // while (i < n) {
        //     while (i < n && s[i] == ' ')
        //         i++;
        //     if (i >= n)
        //         break;
        //     string word = "";
        //     while (i < n && s[i] != ' ')
        //         word += s[i++];
        //     words.push_back(word);
        // }
        // reverse(words.begin(), words.end());
        // string result = "";
        // for (int j = 0; j < words.size(); j++) {
        //     result += words[j];
        //     if (j != words.size() - 1)
        //         result += " ";
        // }
        // return result;

        //Optimal Approach
        //T.C = O(n), S.C = O(1)
        reverse(s.begin(), s.end());
        string ans = "";
        int n = s.size();
        for(int i = 0;i < n; i++){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i++];
            } 
            reverse(word.begin(), word.end());
            if(ans.size() > 0) ans += " "+ word;//if ans is not empty then add a space before adding next word
            else ans += word;
        }
        return ans;
    }
};