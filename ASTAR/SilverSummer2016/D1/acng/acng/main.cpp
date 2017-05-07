//
//  main.cpp
//  acng
//
//  Created by Dhruv Shah on 6/13/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//


#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int firstNumber (int row, int S) {
    int firstNo = S + (row * (row + 3)) / 2;
    return firstNo;
}

int getNumber(int row, int column, int S) {
    if (row == column) {
        return firstNumber(row, S);
    }
    int number = getNumber(row, column - 1, S) + column;
    return number;
}

int main(int argc, const char * argv[]) {
    int N, S;
    cin >> N >> S;
    
    vector<vector<int> > matrix( N, std::vector< int >( N ) );
    
    
    for (int i = 0; i < N; i++) {
        int insert = firstNumber(i, S);
        while (insert > 9) {
            insert -= 9;
        }
        matrix[i][i] = insert;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i != j) {
                int insert = getNumber(i, j, S);
                while (insert > 9) {
                    insert -= 9;
                }
                
                matrix[i][j] = insert;
            }
            
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            cout << matrix[i][j];
            if (j < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
        if (i < N - 1) {
            for (int a = 0; a < i + 1; a++) {
                cout << "  ";
            }
        }
    }
    
    return 0;
}