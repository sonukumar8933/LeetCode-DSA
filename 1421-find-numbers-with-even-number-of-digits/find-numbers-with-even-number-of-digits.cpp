class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int digits=0;
            int temp=nums[i];
            while(temp>0){
                temp=temp/10;
                digits++;
            }
            if(digits%2==0)ans++;
            
        }
        return ans;

        
    }
};