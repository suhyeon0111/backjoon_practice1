#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";

    //1단계
    for (int i = 0; i < new_id.length(); i++){
        if (new_id[i] >= 'A' && new_id[i] <= 'Z'){
            new_id[i] = tolower(new_id[i]); //소문자로 바꿔주기
        }
    }
    
    //2단계
    for (int i = 0; i< new_id.length(); i++){
        if ((new_id[i] >='a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            answer.push_back(new_id[i]);
        }
    }
    
    //3단계
    for (int i = 0; i < answer.size() - 1; i++){
        if (answer[i] == '.' && answer[i+1] == '.'){
            answer.erase(answer.begin() + i); //연속되는 점 제거
            i--; //제거를 했으니 i의 위치를 앞으로 한칸 옮겨주기
        }
    }

    //4단계
    if (answer.front() == '.'){
        answer.erase(answer.begin());
    }
    if (answer.back() == '.'){
        answer.pop_back();
    }
    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if(answer.size() == 0){
        answer.push_back('aaa');
    }
    //6단계
    if (answer.size() > 15){
        answer.erase(15, answer.back() + 1);    
    }
    if (answer.back() == '.'){
        answer.pop_back();
    }
    //7단계
    if (answer.size() <= 2){
        while (answer.size() != 3){
            answer.push_back(answer.back());
        }
    }
    
    return answer;
}
   