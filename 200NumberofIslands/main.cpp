#include <iostream>
#include <vector>

using namespace std;
class Solution {
    //using this array to find the direction
    vector<vector<int>> position = {{1,0},{0,1},{-1,0},{0,-1}};
    //using two variables to define the border
    int m = 0;
    int n = 0;
    vector<vector<bool>> visit;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m==0){
            return 0;
        }
        int res = 0;
       n = grid[0].size();
        vector<vector<bool>> visit1(m,vector<bool>(n,false));
        visit = visit1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!visit[i][j] && grid[i][j]=='1'){
//                    cout<<"jj"<<endl;
                    res++;
                    _iter(grid,i,j);
                }
            }
        }
        return res;
    }
    void _iter(vector<vector<char>>& grid,int startX,int startY){
//        cout<<startX<<startY<<endl;
        for(int i = 0;i<4;i++){
            int x = startX+position[i][0];
            int y = startY+position[i][1];
            if(x>=0 && x<m && y>=0 && y<n && !visit[x][y] && grid[x][y] == '1'){
                visit[x][y]=true;
                _iter(grid,x,y);
            }
        }
    }
};
int main() {
    vector<vector<char>> grid;
    vector<char> item;
    item.push_back('1');
    item.push_back('1');
    item.push_back('0');
    item.push_back('0');
    item.push_back('0');
    grid.push_back(item);
    vector<char> item1;
    item1.push_back('1');
    item1.push_back('1');
    item1.push_back('0');
    item1.push_back('0');
    item1.push_back('0');
    grid.push_back(item1);
    vector<char> item2;
    item2.push_back('0');
    item2.push_back('0');
    item2.push_back('1');
    item2.push_back('0');
    item2.push_back('0');
    grid.push_back(item2);
    vector<char> item3;
    item3.push_back('0');
    item3.push_back('0');
    item3.push_back('0');
    item3.push_back('1');
    item3.push_back('1');
    grid.push_back(item3);


    int cout=Solution().numIslands(grid);
    std::cout << cout<< std::endl;
    return 0;
}