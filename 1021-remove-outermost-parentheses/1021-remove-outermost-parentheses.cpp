class Solution {
public:
    string removeOuterParentheses(string s) {
        //T.C = O(N), S.C = O(N), N = length of string
        string ans = "";
        stack<char> st;
        for(char ch:s){
            if(ch == ')')st.pop();
            if(!(st.empty())) ans+= ch;
            if(ch == '(') st.push(ch); 
        }
        return ans;
    }
};