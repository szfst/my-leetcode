#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;
class Solution {
    //using two variables to define the border
    int m = 0;
    int n = 0;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<pair<int, int>> res;
    vector<vector<bool>> visit;
    bool stopItem;
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m==0){
            return res;
        }
        n = matrix[0].size();
        stopItem=false;
        vector<vector<bool>> pacific1(m,vector<bool>(n,false));
        pacific = pacific1;
        vector<vector<bool>> atlanti1(m,vector<bool>(n,false));
        atlantic = atlanti1;
        vector<vector<bool>> visit1(m,vector<bool>(n,false));
        visit = visit1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i>=1 && j>=1){
                    if(matrix[i][j]==matrix[i-1][j]){
                        if(pacific[i-1][j]&&atlantic[i-1][j]){
                            pacific[i][j]=true;
                            atlantic[i][j]=true;
                            res.emplace_back(i,j);
                        }
                        continue;
                    }
                    if(matrix[i][j]==matrix[i][j-1]){
                        if(pacific[i][j-1]&&atlantic[i][j-1]){
                            pacific[i][j]=true;
                            atlantic[i][j]=true;
                            res.emplace_back(i,j);
                        }
                        continue;
                    }
                }
                    if(i==0 || j== 0)pacific[i][j]=true;
                    if(i==m-1 || j== n-1)atlantic[i][j]=true;
                    visit[i][j] = true;
                    startFlow(matrix,i,j,i,j);
                    stopItem = false;
                    visit[i][j] = false;
            }
        }
        return res;
    }
    void startFlow(vector<vector<int>>& matrix,int startX,int startY,int currentX,int currentY){
        if(pacific[currentX][currentY] && atlantic[currentX][currentY]){
            res.emplace_back(currentX,currentY);
            stopItem = true;
            return;
        }
        if(!stopItem)ifFlow(matrix, startX, startY,0,1,currentX,currentY);
        if(!stopItem)ifFlow(matrix, startX, startY,1,0,currentX,currentY);
        if(!stopItem)ifFlow(matrix, startX, startY,0,-1,currentX,currentY);
        if(!stopItem) ifFlow(matrix, startX, startY,-1,0,currentX,currentY);
    }

    void ifFlow(vector<vector<int>> &matrix, int startX, int startY,int offsetX,int offsetY,int currentX,int currentY) {
        int x = startX+offsetX;
        int y = startY+offsetY;
        if(x==currentX && y==currentY)return;
        if(x>=0 && x < m && y >= 0 && y < n && !visit[x][y] && !stopItem &&matrix[x][y] <= matrix[startX][startY]){
            if(x==0 || y== 0){
                pacific[currentX][currentY]=true;
            }
            if(x == m-1 || y == n-1){
                atlantic[currentX][currentY]=true;
            }
            visit[x][y]=true;
            startFlow(matrix, x, y,currentX,currentY);
            visit[x][y]=false;
        }
    }
};
int main() {
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
//    vector<vector<int>> matrix = {{1,2,2,3},{3,2,3,4}};
//    vector<vector<int>> matrix = {{1,2,2},{3,2,3}};
    Solution().pacificAtlantic(matrix);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}