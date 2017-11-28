#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0)return 0;
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)return 0;
        vector<vector<int>> res(m,vector<int>(n,0));
        res[m-1][n-1]=1;
        for(int i = n-2;i>=0;i--){
            if(obstacleGrid[m-1][i]==0)res[m-1][i]=res[m-1][i+1];
        }
        for(int i = m-2;i>=0;i--){
            if(obstacleGrid[i][n-1]==0)res[i][n-1]=res[i+1][n-1];

        }
        for(int i  = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                if(obstacleGrid[i][j+1]!=1 && obstacleGrid[i+1][j]!=1){
                    res[i][j]=res[i][j+1]+res[i+1][j];
                }else if(obstacleGrid[i][j+1]==1 && obstacleGrid[i+1][j]!=1){
                    res[i][j]=res[i+1][j];
                }else if(obstacleGrid[i+1][j]==1 && obstacleGrid[i][j+1]!=1){
                    res[i][j]=res[i][j+1];
                }
            }
        }
        return res[0][0];
    }
};
int main() {
    vector<vector<int>> obstacleGrid = {{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    std::cout << "Hello, World!" <<Solution().uniquePathsWithObstacles(obstacleGrid)<< std::endl;
    return 0;
}