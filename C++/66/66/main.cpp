//
//  main.cpp
//  66
//
//  Created by 马宁 on 2019/3/5.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int countsum(int row, int col){
    return (row % 10 + row / 10 + col % 10 + col / 10);
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
    int count = 0;
    if(row >= 0 && row < rows && col >= 0 && col < cols){
        if(!visited[row * cols + col] && countsum(row, col) <= threshold){
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) + movingCountCore(threshold, rows, cols, row + 1, col, visited) + movingCountCore(threshold, rows, cols, row, col - 1, visited) + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
    }
    return count;
}

int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <= 0 || cols <= 0) return NULL;
    int count = 0;
    bool* visited = new bool [rows * cols]();
    count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    return count;
}

int main(int argc, const char * argv[]) {
    cout<<movingCount(4, 4, 4)<<endl;
    return 0;
}
