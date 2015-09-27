/*
 ID: dhruv.s2
 PROG: barn1
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

int M, S, C, stalls[201], fillNumber = 1;

/*
    TOTAL NUMBER OF STALLS: S
 
    COW/STALL LIST COUNT:   C
 
    NUMBER OF BOARDS:       M
*/
int boardOne[201];
int board[201];

int* solNBoards(int N) {
    if (N == 1) {
        for (int i = 0; i < C; i++) {
            boardOne[i] = N;
        }
        return boardOne;
    }
    int* boardP = solNBoards(N - 1);
    for (int i = 0; i < C; i++) {
        board[i] = boardP[i];
    }

    // gap find, split two boards
    int largestGap = 1;
    int largestGapIndex = -1;
    for (int i = 1; i < C; i++) {
        if (stalls[i] - stalls[i - 1] > largestGap && board[i] == board[i - 1]) {
            largestGap = stalls[i] - stalls[i - 1];
            largestGapIndex = i;
        }
    }
    if (largestGapIndex < 0) {
        cout << "LG INDEX < 0" << endl;
        return {};
    }
    int index = largestGapIndex;
    int replacingNum = board[index];
    while (index < C && board[index] == replacingNum) {
        board[index] = N;
        index++;
    }
    
    return board;
}

int calcSolution(int boards[]) {
    int totalBlocked = 0;
    
    int curBoard = boards[0];
    
    int startStall = stalls[0];
    int endStall = stalls[C - 1];

    for (int i = 1; i < C; i++) {
        if (boards[i + 1] != curBoard) {
            endStall = stalls[i];
            totalBlocked += endStall - startStall + 1;
            cout << startStall << " " << endStall << " " << endStall - startStall + 1 << endl;
            startStall = stalls[i + 1];
            curBoard = boards[i + 1];
        }
    }
    return totalBlocked;
}

int main(int argc, const char * argv[]) {
    ifstream in("barn1.in");
    ofstream out("barn1.out");

    in >> M >> S >> C;
    for (int i = 0; i < C; i++) {
        in >> stalls[i];
    }
    sort(stalls, stalls + C);
    
    int answer;
    if (M > C) {
        answer = C;
    }
    else {
        answer = calcSolution(solNBoards(M));
    }
    cout << answer << endl;
    out << answer << endl;

    return 0;
}
