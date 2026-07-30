class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>frq;
        for(int x :nums){
            frq[x]++;
            if(frq[x]>1)return x;
        }
        return-1;
    }
};