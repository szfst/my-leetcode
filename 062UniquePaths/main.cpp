#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m,vector<int>(n,-1));
        for(int i = 0;i<n;i++){
            res[m-1][i]=1;
        }
        for(int i = 0;i<m;i++){
            res[i][n-1]=1;
        }
        for(int i  = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                res[i][j]=res[i][j+1]+res[i+1][j];
            }
        }
        return res[0][0];
    }
};
int main() {
    std::cout << "Hello, World!"<<Solution().uniquePaths(1,2) << std::endl;
    return 0;
}