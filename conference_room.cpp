#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//구조체 정의 
struct meeting{
    int start, end;
};

int main(){
    int N;//회의 개수
    meeting arr[1000];//회의 시간 배열 선언
    cin>>N;

    meeting temp; //구조체 변수 temp

    for(int i =0;i<N;i++){  //시작, 종료시간 입력
        int start, finish;
        cin >>start >> finish;
        temp.start = start;
        temp.end = finish;
        arr[i]=temp;
    }
    selection_sort(arr, N);
  
}

int find_big(meeting arr[], int N){ 
    int MAX;
    for(int i =1; i<=N;i++){
        if (arr[i-1].end<arr[i].end){
             MAX = i;
        }
    }
        return MAX;
};
//선택정렬
void selection_sort(meeting arr[], int N ){
    for(int i = 0;i<N;i++){
         int big = find_big(arr, N);//가장 큰 원소의 인덱스 찾기
         meeting tmp = arr[big];
         arr[big]= arr[N-1];
         arr[N-1] = tmp;
         N--;
    }
   


};

