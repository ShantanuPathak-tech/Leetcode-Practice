class Solution {
public:
    int maxDepth(string s) {
        // Brute force
        // T.C = O(N), S.C = O(N/2)
        //  int ans = 0, n = 0;
        //  stack<char> st;
        //  for(char ch:s){
        //      if(ch == '(') st.push(ch);
        //      else if(ch == ')') st.pop();

        //     n = st.size();
        //     ans = ans<n?n:ans;
        // }
        // return ans;

        // Optimal Approach
        //T.C = O(N), S.C = O(1)
        int ans = 0, depth = 0;
        for (char ch : s) {
            if (ch == '(')
                depth++;
            else if (ch == ')')
                depth--;
            ans = ans < depth ? depth : ans;
        }
        return ans;
    }
};