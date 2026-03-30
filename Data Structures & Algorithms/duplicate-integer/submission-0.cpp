class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::vector<int> set;

    for (const auto& element : nums)
    {
        if (std::find(set.begin(), set.end(), element) != set.end())
        {
            return true;
        }
        else
        {
            set.push_back(element);
        }
    }
    return false;
    }
};