#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<vector<int>> conquer;
    vector<vector<pair<int,int>>> resPair;
    int nums;
public:
    int totalNQueens(int n) {
        if(n==0 ||  n==2 )return 0;
        if(n==1){
            return 1;
        }
        vector<vector<int>> conquer1(n,vector<int>(n,0));
        conquer  = conquer1;
        nums = n;
        vector<pair<int,int>> before;
        for(int i = 0;i<nums;i++){
            startConquerOrNot(0,i,1);
            before.emplace_back(0,i);
            solve(1,before);
            before.pop_back();
            startConquerOrNot(0,i,-1);
        }

        return resPair.size();
    }
    void solve(int startRow,vector<pair<int,int>> &before){
        if(startRow==nums){
            if(before.size()==nums){
                resPair.push_back(before);
            }
            return;
        }
        int i = startRow;
        for(int j = 0;j<nums;j++){
            if(conquer[i][j]==0){
                startConquerOrNot(i,j,1);
                before.push_back(make_pair(i,j));
                solve(startRow+1,before);
                before.pop_back();
                startConquerOrNot(i,j,-1);
            }
        }
    }
    void startConquerOrNot(int x,int y,int value){
        vector<vector<bool>> visit(nums,vector<bool>(nums,false));
        for(int i = 0;i<nums;i++){
            conquer[x][i]+=value;
            visit[x][i]=true;
        }
        for(int i = 0;i<nums;i++){
            if(!visit[i][y]){
                conquer[i][y]+=value;
                visit[i][y] = true;
            }

        }
        for(int i = 0;i<nums;i++){
            for(int j = 0;j<nums;j++){
                if(x+y==i+j && !visit[i][j]){
                    conquer[i][j]+=value;
                    visit[i][j] = true;
                }
                if(x-i==y-j && !visit[i][j]){
                    conquer[i][j]+=value;
                    visit[i][j] = true;
                }
            }
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}