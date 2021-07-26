#include <iostream>
using namespace std;
#include <algorithm>


void sort(int A[])  {
for(int i = 0;i<8;i++){
    int m = A[i];
    int index = i;
    for(int j = i+1;j<8;j++)    
    {
        if(m>A[j])
        {
            m = A[j];
            index = j;
        }
    }
    swap(A[i], A[index]);
}
};

int main(){
    int N;
    int A[1000];
    int b;

    cin>>N; //N입력
    for(int i = 0;i<N;i++) {
        cin>>b;
        A[i] = b;
    }
    sort(A);
    int sum1 = 0;
  
    for(int i =1; i<=N;i++){
        for(int j = 0; j<i; j++){
             sum1 = sum1+ A[j];
        }
    }
    cout<<sum1;
}
