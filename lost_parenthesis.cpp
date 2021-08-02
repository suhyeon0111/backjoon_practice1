#include <iostream>
#include <string>
using namespace std;


string s; //입력 값
int num=0; //결과 값
int m=0; //처음에 +인지 -인지 구별해 줄 수 있는 변수
string tmp; //상수를 저장할 수 있도록 하는 변수

//문제 해결 함수
void solve_problem(void){
for(int i = 0; i<=s.size();i++){ 
    if(s[i] == '+' || s[i]=='-' || s[i]=='\0'){ //부호가 있을 때, 문자열이 끝났을때
        if(m){
            num -= stoi(tmp); //밑에 if문에서 부호가 -일때 m=1로 바꿔준 후부터는 모든 수가 -가 됨
        }
        else{
            num += stoi(tmp); //+부호일때 상수 더해주기
        }    
        if(s[i]=='-'){
            m = 1; //-일때 m로 바꿔줌, 후에는 연산자가 +,-가 번갈아 나오기 때문에 수를 더할 일이 없음
        }
        
        tmp="";//새로운 상수가 tmp에 저장될 수 있도록 tmp를 비워줌
        continue;
    } 
    tmp += s[i];//각각 수가 따로 계산되지 않도록 tmp에 합쳐줌

    }
}

int main(int argc, char* argv[]){
    cin>>s; //입력
    solve_problem(); //문제 해결 함수
    cout<<num; //출력
    
}