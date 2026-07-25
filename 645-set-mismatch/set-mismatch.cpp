class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans(2);
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            mp[x]++;
        }
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 2)
                ans[0] = i;
            else if (mp[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};