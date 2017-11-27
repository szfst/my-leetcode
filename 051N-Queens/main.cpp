#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<vector<string>> res;
    vector<vector<int>> conquer;
    vector<vector<pair<int, int>>> resPair;
    int nums;
    vector<bool> colv;
    vector<bool> dia1;
    vector<bool> dia2;

public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0 || n == 2)return res;
        if (n == 1) {
            vector<string> v;
            v.push_back("Q");
            res.push_back(v);
            return res;
        }
        vector<vector<int>> conquer1(n, vector<int>(n, 0));
        conquer = conquer1;
        nums = n;
        vector<pair<int, int>> before;
        for (int i = 0; i < nums; i++) {
            startConquerOrNot(0, i, 1);
            before.emplace_back(0, i);
            solve(1, before);
            before.pop_back();
            startConquerOrNot(0, i, -1);
        }
        for (auto item:resPair) {
            vector<string> sub;
            for (int i = 0; i < nums; i++) {
                string s;
                for (int j = 0; j < nums; j++) {
                    if (item[i].first == i && item[i].second == j) {
                        s += "Q";
                    } else {
                        s += ".";
                    }
                }
                sub.push_back(s);
            }
            res.push_back(sub);
        }
        return res;
    }
    vector<vector<string>> solveNQueens2(int n) {
        colv=vector<bool>(n,false);
        dia1=vector<bool>(2*n-1,false);
        dia2=vector<bool>(2*n-1,false);
        vector<int> row;
        putQueen(n,0,row);
        return res;
    }
    void putQueen(int n,int index,vector<int> &row){
        if(row.size()==n){
            res.push_back(vectorToRes(row,n));
            return;
        }
            for(int i= 0;i<n;i++){
                if(!colv[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                    colv[i] = true;
                    dia1[index+i]=true;
                    dia2[index-i+n-1]=true;
                    row.push_back(i);
                    putQueen(n,index+1,row);
                    row.pop_back();
                    colv[i] = false;
                    dia1[index+i]=false;
                    dia2[index-i+n-1]=false;
                }
            }
    }
    vector<string> vectorToRes(vector<int> row,int n){
        vector<vector<string>> v(n,vector<string>(n,"."));
        vector<string> res;
        for(int i = 0;i<n;i++){
            v[i][row[i]]="Q";
            string item;
            for(int j=0;j<n;j++){
                item+=v[i][j];
            }
            res.push_back(item);
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
    Solution().solveNQueens2(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}