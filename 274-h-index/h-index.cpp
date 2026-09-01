class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end(),greater<int>());
        int ans=0;
        for(int cnt=1;cnt<=n;cnt++){
            bool possible=true;
            for(int i=0;i<cnt;i++){
                if(citations[i]<cnt){
                    possible=false;
                    break;
                
                }
                
            }
            if(possible){
                ans=cnt;
            }
            

        }
        return ans;

        
    }
};