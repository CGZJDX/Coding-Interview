//
//  main.cpp
//  28
//
//  Created by 马宁 on 2019/3/21.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector <int> numbers) {
        /*map<int, int>m;
        for(int i = 0; i < numbers.size(); i ++){
            if(m.count(numbers[i])) m[numbers[i]]++;
            else m[numbers[i]] = 1;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++ ){
            if(it -> second > numbers.size()/2) return it -> first;
        }
        return 0;*/
        if(numbers.empty()){
            return 0;
        }
        int result = numbers[0];
        int count = 1;
        for(int i = 1; i < numbers.size(); i ++){
            if(count == 0){
                count ++;
                result = numbers[i];
            }
            else{
                if(result == numbers[i]) count ++;
                else count --;
            }
        }
        count = 0;
        for(int i = 0; i < numbers.size(); i ++){
            if(numbers[i] == result) count ++;
        }
        return (count > numbers.size() >> 1) ? result : 0;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> numbers = {4, 3, 4, 4, 5, 2, 1, 4, 5, 4, 6};
    Solution sol;
    int result = sol.MoreThanHalfNum_Solution(numbers);
    cout<<result;
    cout<<endl;
    return 0;
}
