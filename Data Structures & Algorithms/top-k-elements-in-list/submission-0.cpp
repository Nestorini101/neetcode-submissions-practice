class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;
        for (int n : nums) {
            nums_count[n]++;
        }
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            pair<int, int> num_max_count(INFINITY, 0);
            for (auto& pair : nums_count) {
                if (pair.second > num_max_count.second) {
                    num_max_count = pair;
                }
            }
            ret.push_back(num_max_count.first);
            nums_count.erase(num_max_count.first);
        }
        return ret;
    }
};