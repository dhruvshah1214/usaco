#include <iostream>
using namespace std;

int N, Q;
int A[100005];

struct node {
    int data, l, r;
    node *left, *right;
};

void createTree(node* cur, int s, int f) {
    if (s > f) {
        return;
    }
    cur->l = s, cur->r = f;
    if (s == f) {
        cur->data = A[f];
        return;
    }
    
    cur->left = new node();
    createTree(cur->left, s, ((s + f)/2));
    
    cur->right = new node();
    createTree(cur->right, ((f + s)/2) + 1, f);
    //cur->left->data = As[(int)((f + s)/2)] - As[s - 1];
    //cur->right->data = As[f] - As[(int)((f + s)/2)];
    cur->data = min(cur->left->data, cur->right->data);    
    
}

void updateTree(node* root, int ind, int val) {
    if(root->l == root->r) {
        A[ind] += val;
        root->data += val;
    }
    else {
        int mid = (root->l + root->r)/2;
        if(ind <= mid) {
            updateTree(root->left, ind, val);
        }
        else {
            updateTree(root->right, ind, val);
        }
        root->data = min(root->left->data, root->right->data);
    }
}

int queryTree(node* cur, int l, int r)
{
    if(r < cur->l || cur->r < l)
    {
        // range represented by a node is completely outside the given range
        return (1 << 29);
    }
    if(l <= cur->l && cur->r <= r)
    {
        // range represented by a node is completely inside the given range
        return cur->data;
    }
    // range represented by a node is partially inside and partially outside the given range
    int p1 = queryTree(cur->left, l, r);
    int p2 = queryTree(cur->right, l, r);
    return min(p1, p2);
}




int main()
{
    cin >> N >> Q;
    node* root = new node();
    
    root->l = 1;
    root->r = N;
    
    for(int i = 1; i<= N; i++) {
        cin >> A[i];
        //cout << A[i] << " ";
    }
    //cout << endl;
    
    createTree(root, 1, N);
    //cout << queryTree(root, 1, 3) << endl;
    for(int i = 0; i < Q; i++) {
        char c;
        int a, b;
        cin >>c >> a >> b;
        if(c == 'q') {
            cout << queryTree(root, a, b) << endl;
        }
        else if(c == 'u') {
            updateTree(root, a, b - A[a]);
        }
        else {
            cout << "UHOH";
        }
    }
    
    return 0;
}
