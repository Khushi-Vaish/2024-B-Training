#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &a,int n,int i){
    int maxIdx = i;
    int l= 2*i+1;
    int r= 2*i+2;
    if(l<n && a[l]>a[maxIdx]){
        maxIdx=l;
    }
    if(r<n && a[r]>a[maxIdx]){
        maxIdx=r;
    }
    if(maxIdx!=i){
        swap(a[maxIdx],a[i]);
        heapify(a,n,maxIdx);
    }
}

void heapSort(vector<int> &a){
    int n=a.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    heapSort(a);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}