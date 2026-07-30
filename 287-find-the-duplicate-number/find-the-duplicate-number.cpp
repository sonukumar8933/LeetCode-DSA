class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>frq;
        for(int x:nums){
            if(frq.contains(x)){
                return x;

            }
            frq.insert(x); 
        }
        return -1;
       

        
    }
};