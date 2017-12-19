#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {

public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int res = 0;
        int pre = 0;
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i].start<intervals[pre].end){
                res++;
                //如果这样，移去的应该是之前的，也就是说，遇到一个区域在另外一个区域里面，移去的应该是大的区域，这样能保证移去最少的区域
                if(intervals[i].end<intervals[pre].end){
                    pre = i;
                }
            }else{
                pre = i;
            }
        }
        return res;

    }
};
int main() {
    Interval interval3[] = {Interval(1,2)};
    vector<Interval> v3( interval3, interval3 + sizeof(interval3)/sizeof(Interval));
    cout<<Solution().eraseOverlapIntervals(v3)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}