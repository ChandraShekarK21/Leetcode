class Solution {
public:
    int m,n;
    void dfs(int r,int c,vector<vector<int>>& grid, int k,vector<vector<bool>>& visited,long long & sum){
        visited[r][c]=true;
        sum+=grid[r][c];
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int x=0;x<4;x++){
            int nr=r+dr[x];
            int nc=c+dc[x];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0 && visited[nr][nc]==false){
                dfs(nr,nc,grid,k,visited,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && visited[i][j]==false){
                    long long sum=0;
                    dfs(i,j,grid,k,visited,sum);
                    if(sum%k==0)count++;
                }
            }
        }
        return count;
    }
};