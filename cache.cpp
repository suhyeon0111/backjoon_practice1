#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int cache_time = 0;

    if (cacheSize == 0) {
        cache_time = 5 * cities.size();
        return cache_time;
    }

    vector<string> cache;

    for (int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); // 소문자 변환하기
        int j; //캐시 인덱스
        for (j = 0; j < cache.size(); j++) {

            if (cities[i] == cache[j]) { //hit 했을 때
                cache.erase(cache.begin() + j); 
                cache.push_back(cities[i]); ////hit한 값을 push_back넣어서 최근 사용 표시를 함
                cache_time++; // 시간 1증가
                break;
            }
        }

        if (j == cache.size()){ //miss일 때
            cache_time += 5; //시간 5증가
            if (cache.size() == cacheSize) { //포화상태일때
                cache.erase(cache.begin()); //오래된 거 지우기
            }
            cache.push_back(cities[i]);
        }
    }
    return cache_time;
}
