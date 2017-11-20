#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<=3){
            return res;
        }
        _restoreIpAddresses(s,1,"");
        return res;
    }
    void _restoreIpAddresses(string s,int dotCount,string before) {
          if(s.empty()){
              return;
          }
//        cout<<"s:"<<s<<" dotCount:"<<dotCount<<" before:"<<before<<endl;
          if(dotCount==4 ){
              //if we arrive at the final string,check s to improve the algorithm and get the right answer
              if(s.size()<=3 && atoi(s.c_str()) <= 255){
                  if(checkZero(s)){
                  res.push_back(before+s);}

              }
              return;
           }
            for(int i = 1;i<4&&i<s.size();i++){
                string pre = s.substr(0,i);
                if(atoi(pre.c_str())<=255){
                    if(checkZero(pre)){
                        string be = s.substr(i,s.size());
                        _restoreIpAddresses(be,dotCount+1,before+pre+".");
                    }
                }
            }
    }
    bool checkZero(string s){
        if(s.empty()){
            return false;
        }
        if(s.substr(0,1)=="0"){
            return s.size()==1;
        }else{
            return true;
        }
    }


};
int main() {
    vector<string> res = Solution().restoreIpAddresses("010010");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}