#include <iostream>
using namespace std;


int main(){
    int N,K,b;
    cin>>N>>K;//동전이 N종류,총 가치의 합 K
    int C[10];//동전 단위

    //배열에 동전 단위 입력
    for(int i =0;i<N;i++){
        cin>>b;
        C[i]=b;
    }

    int sum = 0;//최종 구하려는 동전의 최소 개수
    
    //동전의 최소 개수 구하는 알고리즘
    for(int i = N-1; i>=0 ;i--){
        int j  =K/C[i];
        K = K-(C[i]*j);
        sum+=j;
    }
    cout<<sum;
}