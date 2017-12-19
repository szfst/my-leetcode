#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int cks = 0;
        int greed = 0;
        int res = 0;
        while(cks<s.size() && greed<g.size()){
            if(g[greed]<=s[cks]){
                cks++;
                greed++;
                res++;
            }else{
                greed++;
            }
        }
        return res;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}