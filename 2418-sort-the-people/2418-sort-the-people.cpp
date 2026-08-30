class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //Time Complexity:- O(n log(n))
        //Space Complexity:- O(n)
        int n = names.size();
        
        // Pair height with name: vector<pair<int, string>>
        vector<pair<int, string>> people(n);
        for (int i = 0; i < n; ++i) {
            people[i] = {heights[i], names[i]};
        }
        
        // Sort in descending order based on height
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Extract the sorted names
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = people[i].second;
        }
        
        return result;
    }
};