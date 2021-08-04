#include <iostream>
#include <algorithm>
using namespace std;

int rope[100000]; //각 로프가 버틸 수 있는 중량 배열

//오름차순 정렬
bool compare(int i, int j){
    return j<i;
}
int main(){
    int N;//로프 개수
    cin>>N;

    //각 로프 중량 입력
    for(int i = 0; i<N; i++){
        cin >> rope[i];
    }
    sort(rope, rope+N,compare);//오름차순으로 정렬

    //최대 중량이 나올 수 있는 모든 경우의 수 계산하여 다시 배열에 입력
    for(int i =0; i<N;i++){
        rope[i]=rope[i]*(i+1);
    }

    sort(rope, rope+N);//내림차순으로 정렬 (오름차순으로 정렬해도 무관/대신 출력의 인덱스를 0으로 바꿔주기)

    cout<<rope[N-1];//최대 중량 출력
}