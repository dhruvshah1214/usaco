//
//  main.cpp
//  Cow Checkers
//
//  Created by Dhruv Shah on 6/21/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int N, M, T, corrow[2000001];

void gen2n() {
    int xinc = 0;
    int yinc = 0;
    corrow[0] = 0;
    for (int i = 0; i < max(N, M); i++) {
        xinc += 2;
        yinc += 1;
        if (xinc > max(N, M) || yinc > max(N, M)) {
            break;
        }
        while (corrow[yinc] != -1) {
            xinc++, yinc++;
        }
        corrow[xinc] = yinc;
        corrow[yinc] = xinc;
    }
}

void getans(int xloc, int yloc) {
    if (corrow[xloc] == yloc) {
        printf("Farmer John\n");
    }
    else {
        printf("Bessie\n");
    }  
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &N, &M, &T);
    memset(corrow, -1, sizeof(corrow));
    gen2n();
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        getans(a, b);
    }
    
    return 0;
}
