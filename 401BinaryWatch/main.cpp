#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
    vector<vector<int>> indexRes;

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<bool> used(11,false);
        vector<int> before;

        _readBinaryWatch(num,before,used);
        for(vector<int> item:indexRes){
            string r = "";
            if(timeValid(item,r)){
                res.push_back(r);
            }
        }
        return res;
    }
    bool timeValid(vector<int> item,string &res){
        vector<bool> isLight(10, false);
        int hour=0;
        int minutes=0;
        for(auto i:item){
                if(i<4){
                    hour += pow(2,i);
                }else{
                    int temp = i-4;
                    minutes += pow(2,temp);
                }
        }
        if(hour>=12){
            return false;
        }
        if(minutes>=60){
            return false;
        }
        res = to_string(hour)+":";
        res+=minutes<10?("0"+to_string(minutes)):(to_string(minutes)+"");
        return true;
    }
    void _readBinaryWatch(int num,vector<int> before,vector<bool> used){
        if(before.size()==num){
            indexRes.push_back(before);
            return;
        }
        for(int i = 0;i<10;i++){
            if(!used[i]){
                before.push_back(i);
                used[i]=true;
                _readBinaryWatch(num,before,used);
                before.pop_back();
            }
        }
    }
};
int main() {
    Solution().readBinaryWatch(1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}