#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1000
int n;
int a[MAX];
int CBT[MAX];
int index=0;
void inOrder(int root);
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    inOrder(1);
    for(int i=1;i<=n;i++){
        printf("%d",CBT[i]);
        if(i<n) printf(" ");
    }
    return 0;
}
 
void inOrder(int root){
    if(root>n){
        return;
    }
    inOrder(2*root);
    CBT[root]=a[index++];
    inOrder(2*root+1);
}