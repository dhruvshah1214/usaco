//
//  main.cpp
//  High Card Low Card
//
//  Created by Dhruv Shah on 6/29/16.
//  Copyright © 2016 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int elsf[25005], elss[25005];
int bf[25005], bs[25005];

bool elsie[100005];

bool desc(const int &a, const int& b) {
    return b < a;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i < (N / 2)) {
            cin >> elsf[i];
            elsie[elsf[i]] = true;

        }
        else {
            cin >> elss[i - (N / 2)];
            elsie[elss[i - (N / 2)]] = true;
        }
    }
    
    sort(elsf, elsf + (N / 2));
    sort(elss, elss + (N / 2), desc);
    
    
    int numCard = 0;
    for (int i = 2 * N; i >= 1; i--) {
        if (!elsie[i]) {
            if (numCard < (N / 2)) {
                bf[numCard] = i;
                numCard++;
            }
            else {
                bs[numCard - (N / 2)] = i;
                numCard++;
            }
        }
        
    }
    
    sort(bf, bf + (N / 2));
    sort(bs, bs + N / 2, desc);
    /*
    for (int i = 0; i < (N / 2) ; i++) {
        cout << elsf[i] << " " << elss[i] << " " << bf[i] << " " <<  bs[i] << endl;
    }
     */
    
    int points = 0;
    int prevB = 0;
    for (int i = 0; i < (N / 2); i++) {
        int elsiesCard = elsf[i];
        // find lowest card that beats it
        int j = prevB;
        for (; j < (N / 2); j++) {
            if (bf[j] >  elsiesCard) {
                points++;
                break;
            }
        }
        if (j != (N / 2)) {
            prevB = j + 1;
        }
        else {
            break;
        }
    }
    
    prevB = 0;
    for (int i = 0; i < (N / 2); i++) {
        int elsiesCard = elss[i];
        // find lowest card that beats it
        int j = prevB;
        for (; j < (N / 2); j++) {
            if (bs[j] < elsiesCard) {
                points++;
                break;
            }
        }
        if (j != (N / 2)) {
            prevB = j + 1;
        }
        else {
            break;
        }

    }
    cout << points << endl;
    
    
    return 0;
}

























































/*
 This problem seems daunting at first, but a few insights can give way to a greedy strategy for solving it:
 
 - You're free to mentally rearrange Elsie's cards however you like within each half, since you know what she's going to play, and you can simply "match" your cards to hers.
 
 - It's always best to use your N/2 highest cards in the first half, and your N/2 lowest cards in the second half. This means we can consider both halves completely independently, since we know which cards are going to be played in each.
 
 (For the remainder of the analysis, we'll only consider the first half -- the second half can be analyzed with very similar arguments.)
 
 - If you're aiming for X points, then you should always aim to beat Elsie's X lowest cards. This is because, if Bessie can beat some set made of X of Elsie's cards, then you can always swap Elsie's cards for lower cards without losing any points.
 
 - If you want to beat one of Elsie's cards, you should always do it with the lowest possible card you can do it with. After all, having a higher card in your hand is strictly better than having a lower card in your hand.
 
 This hints at a greedy solution: for each of Elsie's cards in ascending order, find the lowest possible card you have that beats it, play that card against hers, and try to beat the next one. Some thinking can convince you that this is the best possible solution, since it's the "lexicographically lowest" -- intuitively, each card played so far is the minimum possible card you could have played, so you'll have the maximum possible number of high cards available for you to use.
 
*/