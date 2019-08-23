#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void buildtree(vector<int> &tree, int n , int i, int j, int *arr){
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
    int i = 0,count = 0;
    int num = n;
    while(num>0){
        if(num%2 == 1){
            i = -1;
            break;
        }
        num >>= 1;
        if(num == 1)
            break;
    }
    if( i == 0){
        return 2*n;
    }
    n *= 2;
    while(n>0){
        count++;
        if(n&1 == 1)
            i = count;
        n >>= 1;
    }
    return pow(2,i);
}

int getsum(vector<int> &tree, int n, int i,int j,int l,int r){
    if( r < i || l > j)
        return 0;
    if(l<= i && j<=r)
        return tree[n];
    
    int mid = i+(j-i)/2;
    return (getsum(tree, 2*n,i,mid,l,r)+ getsum(tree, 2*n+1, mid+1,j,l,r));
}

int main(){
    int n = 6;
    int arr[] = {1,3,5,7,9,11};
    int x = sizeoftree(n);
    vector<int> tree(x,-1);
    buildtree(tree,1,0,n-1,arr);
    cout<<getsum(tree,1,0,n-1,1,5)<<"\n";
    return 0;
}