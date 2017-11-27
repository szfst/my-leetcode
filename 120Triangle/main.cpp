#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
    vector<vector<int>> visit;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()){
            return 0;
        }
        for(auto item:triangle){
            vector<int> vector1;
            for(int inner:item){
                int o2 = -1;
                vector1.push_back(o2);
            }
            visit.push_back(vector1);
        }
        int depth = triangle.size();
        for(int i = 0;i<triangle[depth-1].size();i++){
            visit[depth-1][i]=triangle[depth-1][i];
        }
        for(int i = depth-2;i>=0;i--){
            int innerSize = visit[i].size();
            for(int j = 0;j<innerSize;j++){
                visit[i][j]=triangle[i][j]+min(visit[i+1][j],visit[i+1][j+1]);
            }
        }
        return visit[0][0];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}