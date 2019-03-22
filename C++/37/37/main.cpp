//
//  main.cpp
//  37
//
//  Created by 马宁 on 2019/2/24.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int FirstLoc(vector<int> data, int k, int begin, int end){
    if(begin > end) return -1;
    int mid = (begin + end) >> 1;
    if(data[mid] == k){
        if((mid > begin && data[mid - 1] != k) || (mid == begin)) return mid;
        else end = mid - 1;
    }
    else if(data[mid] > k) end = mid - 1;
    else begin = mid + 1;
    return FirstLoc(data, k, begin, end);
}
int LastLoc(vector<int> data, int k, int begin, int end){
    if(begin > end) return -1;
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if(data[mid] == k){
            if((mid < end && data[mid + 1] != k) || (mid == end)) return mid;
            else begin = mid + 1;
        }
        else if(data[mid] > k) end = mid - 1;
        else begin = mid + 1;
    }
    return -1;
}
int GetNumberOfK(vector<int> data ,int k) {
    int len = data.size() - 1;
    if(k < data[0] || k > data[len]) return 0;
    int firstloc = FirstLoc(data, k, 0, len);
    int lastloc = LastLoc(data, k, 0, len);
    if(firstloc != -1 && lastloc != -1){
        return lastloc - firstloc + 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,3,3,3,4,5};
    int b = GetNumberOfK(a, 3);
    cout<<b<<endl;
    return 0;
}
