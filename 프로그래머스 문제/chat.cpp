#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> ID;
    vector<string> state;
    map<string, string> nickname;
    vector<string> answer;

    for(int i = 0; i < record.size(); i++) {//백터 차례로 
        string str[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;
            
        while(ss >> token)
            str[index++] = token;
        //문자열 띄어쓰기를 기준으로 나눠주기

        //"enter"일 때
        if (str[0] == "Enter") {
            state.push_back("님이 들어왔습니다."); //상태를 vector에 쌓기
            ID.push_back(str[1]); //어떤 아이디가 들어왔는지 vector에 쌓기
            nickname[str[1]] = str[2]; //닉네임 바꿔주기
        }

        //"change"일 때
        if (str[0] == "Change") {
            nickname[str[1]] = str[2]; //닉네임 바꿔주기
        }
        //"leave"일 때
        if (str[0] == "Leave") {
            state.push_back("님이 나갔습니다.");
            ID.push_back(str[1]);
        }
        ss.clear();
    }


    for(int i = 0; i < state.size(); i++){
       answer.push_back(nickname[ID[i]] + state[i]);
    }

    return answer;
}

