//
//  main.cpp
//  45
//
//  Created by 马宁 on 2019/3/7.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool IsContinuous(vector<int> numbers) {
    if(numbers.size() == 0) return false;
    int flag = 0;
    int low = 14, high = 0;
    for(int i = 0; i < numbers.size(); i ++){
        int number = numbers[i];
        if(number < 0 || number > 13) return false;
        if(number == 0) continue;
        if((flag >> number & 1) == 1) return false;
        flag |= 1 << number;
        if(low > number) low = number;
        if(high < number) high = number;
        if(high - low > 4) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 0, 3, 0, 5};
    bool sign;
    sign = IsContinuous(numbers);
    cout<<sign<<endl;
    return 0;
}
