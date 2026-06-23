class Solution {
public:

    void dfs(vector<vector<int>>& stones,int index,vector<bool>&Visited){
        Visited[index]=true;

        for(int i=0;i<stones.size();i++){
            int r=stones[index][0];
            int c=stones[index][1];
            if((Visited[i]==false) && (stones[i][0]==r || stones[i][1]==c)){
                dfs(stones,i,Visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n= stones.size();
        vector<bool>Visited(n,false);

        int group=0;
        for(int i=0;i<n;i++){
            if(Visited[i]==true)
                 continue;

            dfs(stones,i,Visited);
            group++;     
        }

        return (n-group);
        
    }
};