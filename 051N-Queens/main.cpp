#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<vector<string>> res;
    vector<vector<int>> conquer;
    vector<vector<pair<int,int>>> resPair;
    int nums;
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==0 ||  n==2 )return res;
        if(n==1){
            vector<string> v;
            v.push_back("Q");
            res.push_back(v);
            return res;
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
        for(auto item:resPair){
            vector<string> sub;
            for(int i = 0;i<nums;i++){
                string s;
                for(int j = 0;j<nums;j++){
                    if(item[i].first==i && item[i].second==j){
                        s+="Q";
                    }else{
                        s+=".";
                    }
                }
                sub.push_back(s);
            }
            res.push_back(sub);
        }
        return res;
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
    Solution().solveNQueens(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}