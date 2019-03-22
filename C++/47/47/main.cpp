//
//  main.cpp
//  47
//
//  Created by 马宁 on 2019/3/8.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

/*int Sum_Solution(int n) {
    if(n < 1) return NULL;
    int ans = n;
    ans && (ans += Sum_Solution(n - 1));
    return ans;
}*/

int Sum_Solution_Core(int a, int b){
    int sum = 0;
    ((a & 1) == 1) && (sum += b);
    (a != 0) && (sum += Sum_Solution_Core(a >> 1, b << 1));
    return sum;
}

int Sum_Solution(int n) {
    int a = n, b = n + 1;
    return Sum_Solution_Core(a, b) >> 1;
}

int main(int argc, const char * argv[]) {
    int ans;
    ans = Sum_Solution(5);
    cout<<ans<<endl;
    return 0;
}
