#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minPathSum2(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();
        if(n==0)return 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        visit[m-1][n-1]=grid[m-1][n-1];
        for(int i = n-2;i>=0;i--){
            visit[m-1][i]=visit[m-1][i+1]+grid[m-1][i];
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(j+1>=n){
                    visit[i][j]=grid[i][j]+visit[i+1][j];
                    continue;
                }
                visit[i][j]=grid[i][j]+min(visit[i][j+1],visit[i+1][j]);
            }
        }
        return visit[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0)return 0;
        int n = grid[0].size();
        if(n==0)return 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i+1>=m && j+1>=n){
                    visit[i][j]=grid[i][j];
                    continue;
                }
                if(i+1>=m){
                    visit[i][j]=grid[i][j]+visit[i][j+1];
                    continue;
                }
                if(j+1>=n){
                    visit[i][j]=grid[i][j]+visit[i+1][j];
                    continue;
                }
                visit[i][j]=grid[i][j]+min(visit[i][j+1],visit[i+1][j]);
            }
        }
        return visit[0][0];
    }
};
int main() {
    vector<vector<int>> grid = {{1,2},{1,1}};
    Solution().minPathSum(grid);
    std::cout << "Hello, World!" <<Solution().minPathSum(grid)<< std::endl;
    return 0;
}