class Solution {
public:
    string intToRoman(int num) {
        //T.C = O(1);
        string roman = "";
        vector<pair<int, string>> intToroman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        for (int i = 0; i < intToroman.size(); i++) {
            while (num >= intToroman[i].first) {
                roman += intToroman[i].second;
                num -= intToroman[i].first;
            }
        }
        return roman;
    }
};