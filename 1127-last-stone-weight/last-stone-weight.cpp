class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int max1 = stones.back();
            stones.pop_back();
            int max2 = stones.back();
            stones.pop_back();
            if (max1 == max2)
                continue;
            else {
                stones.push_back(max1 - max2);
            }
        }
        if (stones.empty()) {
            return 0;
        }
        return stones[0];
    }
};