#include<iostream>
using namespace std;

void buildtree(int *tree, int n , int i, int j, int *arr){
    if(i == j){
        tree[n] = arr[i];
        return;
    }
    int mid = i + (j-i)/2;
    int l = 2*n, r = 2*n+1;
    buildtree(tree,l,i,mid,arr);
    buildtree(tree,r,mid+1,j,arr);
    tree[n] = tree[l]+tree[r];   // sum 
}

int sizeoftree( int n){
    int i ,count = 0;
    while(n>0){
        count++;
        if(n&1 == 1)
            i = count;
        n >>= 1;
    }
    return 2*i -1;
}

int main(){

    return 0;
}