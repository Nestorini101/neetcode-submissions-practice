class Solution {
   public:
    int charToIndex(char c) { return c - 'a'; }
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        const int num_chars = charToIndex('z') + 1;
        std::vector<int> count(num_chars, 0);

        for (char c : s) {
            count.at(charToIndex(c))++;
        }

        for (char c : t) {
            count.at(charToIndex(c))--;
        }

        for (int x : count) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};