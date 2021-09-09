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

    for(int i = 0; i < record.size(); i++) {//���� ���ʷ� 
        string str[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;
            
        while(ss >> token)
            str[index++] = token;
        //���ڿ� ���⸦ �������� �����ֱ�

        //"enter"�� ��
        if (str[0] == "Enter") {
            state.push_back("���� ���Խ��ϴ�."); //���¸� vector�� �ױ�
            ID.push_back(str[1]); //� ���̵� ���Դ��� vector�� �ױ�
            nickname[str[1]] = str[2]; //�г��� �ٲ��ֱ�
        }

        //"change"�� ��
        if (str[0] == "Change") {
            nickname[str[1]] = str[2]; //�г��� �ٲ��ֱ�
        }
        //"leave"�� ��
        if (str[0] == "Leave") {
            state.push_back("���� �������ϴ�.");
            ID.push_back(str[1]);
        }
        ss.clear();
    }


    for(int i = 0; i < state.size(); i++){
       answer.push_back(nickname[ID[i]] + state[i]);
    }

    return answer;
}

