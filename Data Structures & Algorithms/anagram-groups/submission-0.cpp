class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int num_chars = charToIndex('z') + 1;
        map<vector<int>, vector<string>> anagram_groups;

        for (const string& s : strs) {
            vector<int> char_count(num_chars, 0);
            for (char c : s) {
                char_count.at(charToIndex(c))++;
            }

            auto it = anagram_groups.find(char_count);

            if (it == anagram_groups.end()) {
                vector<string> new_group;
                new_group.push_back(s);
                anagram_groups.insert({char_count, new_group});
            } else {
                it->second.push_back(s);
            }
        }
        vector<vector<string>> ret;
        for (const auto& pair : anagram_groups) {
            ret.push_back(pair.second);
        }
        return ret;
    }
    int charToIndex(char c) { return c - 'a'; }
};