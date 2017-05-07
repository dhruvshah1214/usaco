//
//  main.cpp
//  Overplanting
//
//  Created by Dhruv Shah on 7/1/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, x1[1005], y1[1005], x2[1005], y2[1005], all_x[2005];

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        all_x[2 * i] = x1[i];
        all_x[2 * i + 1] = x2[i];
    }
    sort(all_x, all_x + 2 * N);
    
    long long answer = 0;
    int i = 0;
    while(i < 2 * N)
    {
        int x = all_x[i];
        if(i != 0 && x == all_x[i - 1])
        {
            i++;
            continue;
        }
        vector<pair<long long, long long> > rects;
        for(int j = 0; j < N; j++)
            if(x1[j] <= x && x2[j] > x)
            {
                rects.push_back(make_pair(y2[j], 1));
                rects.push_back(make_pair(y1[j], -1));
            }
        if(rects.size() == 0)
        {
            i++;
            continue;
        }
        sort(rects.begin(), rects.end());
        long long cur_area = 0;
        int num_rectangles = 0, pos = 0;
        while(pos < rects.size())
        {
            long long bottom_y = rects[pos].first;
            num_rectangles += rects[pos].second;
            while(num_rectangles > 0)
                num_rectangles += rects[++pos].second;
            long long top_y = rects[pos].first;
            cur_area += top_y - bottom_y;
            pos++;
        }
        int j = i + 1;
        while(all_x[j] == all_x[i])
            j++;
        answer += cur_area * (all_x[j] - x);
        i = j;
    }
    
    printf("%lld\n", answer);
    
    return 0;
}
