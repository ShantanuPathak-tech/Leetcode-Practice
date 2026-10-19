class Solution {
public:
    string frequencySort(string s) {
        //Brute force
        //T.C = n^2 log n;
        // unordered_map<char, int> freq;
        // for(char c : s) freq[c]++;
        
        // string result = "";
        // while(!freq.empty()){
        //     char maxChar;
        //     int maxFreq = 0;
            
        //     for(auto it: freq){
        //         if(it.second > maxFreq){
        //             maxFreq = it.second;
        //             maxChar = it.first;
        //         }
        //     }
        //     result += string(maxFreq, maxChar);
        //     freq.erase(maxChar);
        // }
        // return result;

        //Optimal Approach
        //T.C = O(n), S.C = O(n)
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;

        vector<vector<char>> bucket(s.size() + 1);
        for(auto& [ch, f] : freq){
            bucket[f].push_back(ch);
        }
        string result = "";
        for(int i = s.size(); i >= 1;--i){
            for(char ch: bucket[i]){
                result += string(i, ch);
            }
        }
        return result;
    }
};