//
//  main.cpp
//  65
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

bool ishasPath(char* matrix, int rows, int cols, char* str, int row, int col, bool *ishas){
    if(*str == '\0') return true;
    bool sign = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols){
        if(ishas[row * cols + col] || matrix[row * cols + col] != *str) return false;
        ishas[row * cols + col] = true;
        sign = ishasPath(matrix, rows, cols, str + 1, row - 1, col, ishas) || ishasPath(matrix, rows, cols, str + 1, row + 1, col, ishas) || ishasPath(matrix, rows, cols, str + 1, row, col - 1, ishas) || ishasPath(matrix, rows, cols, str + 1, row, col + 1, ishas);
        ishas[row * cols + col] = false;
    }
    return sign;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == NULL || str == NULL || rows <= 0 || cols <= 0) return false;
    bool *ishas = new bool [rows * cols]();
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            if(ishasPath(matrix, rows, cols, str, i, j, ishas)){
                delete[] ishas;
                return true;
            }
        }
    }
    delete[] ishas;
    return false;
}

int main(int argc, const char * argv[]) {
    char a[] = {"ABCESFCSADEE"};
    char b[] = {"ABCCED"};
    //char c[] = {"abcb"};
    cout<<hasPath(a, 3, 4, b)<<endl;
    //cout<<hasPath(a, 3, 4, c)<<endl;
    /*bool *a = new bool [10];
    for(int i = 0; i < 10; i ++) a[i] = 1;
    for(int i = 0; i < 10; i ++) cout<<a[i];
    cout<<endl;*/
    return 0;
}
