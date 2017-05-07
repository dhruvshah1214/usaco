//
//  main.cpp
//  Maximum Sum
//
//  Created by Dhruv Shah on 3/28/17.
//  Copyright © 2017 Dhruv Shah. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, A[100006];
int Q;

struct segtree {
    struct node {
        int l, r;
        node *left, *right;
        int maxSum, maxNum;
    } *root;
    int size;
    
    segtree(int a) {
        size = a;
        createTree(root, 1, a);
    }
    
    void createTree(node* cur, int s, int f) {
        if (s > f) {
            return;
        }
        cur->l = s, cur->r = f;
        if (s == f) {
            cur->maxSum = 0;
            cur->maxNum = A[f];
            return;
        }
        
        cur->left = new node();
        //cur->left->data = As[(int)((f + s)/2)] - As[s - 1];
        createTree(cur->left, s, ((s + f)/2));
        
        cur->right = new node();
        //cur->right->data = As[f] - As[(int)((f + s)/2)];
        createTree(cur->right, ((f + s)/2) + 1, f);
        
        cur->maxNum = max(cur->left->maxNum, cur->right->maxNum);
        cur->maxSum = max(max(cur->left->maxSum, cur->right->maxSum), cur->left->maxNum + cur->right->maxNum);
    }
    
    void updateTree(int ind, int val) {
        updateTree(root, ind, val);
    }
    
    void updateTree(node* cur, int ind, int val) {
        if(cur->l == cur->r) {
            A[ind] = val;
            cur->maxSum = 0;
            cur->maxNum = val;
        }
        else {
            int mid = (cur->l + cur->r)/2;
            if(ind <= mid) {
                updateTree(cur->left, ind, val);
            }
            else {
                updateTree(cur->right, ind, val);
            }
            cur->maxNum = max(cur->left->maxNum, cur->right->maxNum);
            cur->maxSum = max(max(cur->left->maxSum, cur->right->maxSum), cur->left->maxNum + cur->right->maxNum);    
        }
    }
    
    node* queryTree(int l, int r) {
        return queryTree(root, l, r);
    }
    
    node* queryTree(node* cur, int l, int r)
    {
        if(r < cur->l || cur->r < l)
        {
            // range represented by a node is completely outside the given range
            node* niln = new node();
            niln->maxSum = 0;
            niln->maxNum = 0;
            return niln;
        }
        if(l <= cur->l && cur->r <= r)
        {
            // range represented by a node is completely inside the given range
            return cur; 
        }
        // range represented by a node is partially inside and partially outside the given range
        node* p1 = queryTree(cur->left, l, r);
        node* p2 = queryTree(cur->right, l, r);
        node* rn = new node();
        rn->maxNum = max(p1->maxNum, p2->maxNum);
        rn->maxSum = max(max(p1->maxSum, p2->maxSum), p1->maxNum + p2->maxNum);
        return rn;
    }

    
};


int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    segtree *s = new segtree(N);
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'Q') {
            cout << s->queryTree(a, b)->maxSum << endl;
        }
        else if (c == 'U') {
            s->updateTree(a, b);
        }
        else {
            cout << "UHOHHOH" << endl;
        }
    }
    
    
    
    
    return 0;
}
