class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans;
        int left=0;
        int right=n-1;
        while(left<right){

            int sum=numbers[left]+numbers[right];

             if(sum==target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            if(sum<target){
                left++;
            }
            else{
                right--;
            }
           


        }
        return ans;

       
        
    }
};