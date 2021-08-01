#include <iostream>
using namespace std;
#include <string>

int num = 0;
int m = 0;
string tmp = "";
string s;

void find_num(void)
{
	for (int i = 0; i <= s.size(); ++i){
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0'){
			if (m) {
				num -= stoi(tmp);
			}
			else {
				num += stoi(tmp);
			}
 
			if (s[i] == '-') {
				m = 1;
			}
 
			tmp = "";
			continue;
		}
 
		tmp += s[i];
	}
}

int main(int argc, char *argv[]){
    cin>>s;
    find_num();//문제 해결함수
    cout<<num;//최소값 출력
}