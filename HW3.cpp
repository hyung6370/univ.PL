#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void fileRead(vector<string>& v, ifstream &fin) { // 파일 읽기
  string line;  
  while(getline(fin, line))  // 라인 읽어들여서
    v.push_back(line);    // push_back

  cout << v.size() << "단어를 읽었습니다." << endl;
}

void search(vector<string>& v, string word, int i, int j) { // 단어 검색
  int count = 0;
  string word2 = word;  // word를 word2로 이동
    word.erase(word.begin() + j);  // 입력 받은 word 단어 시작부터 j만큼 글자 지운다 
    for (auto it = v.begin(); it != v.end(); it++) {  // 벡터 처음부터 끝까지 단어 찾기
      int index = (*it).find(word);  // 입력받은 word 찾은 것을 index로 
      string tmp = *it;  // *it 임시로 저장
      int tmp_count = 0; // 임시로 저장한 tmp의 count
      if (index != -1) {  // 찾는 단어가 있고,
        if (tmp.length() == i) {  // tmp의 길이가 word의 길이와 같다면
          for (int k = 0; k < i; k++) { // for 문을 단어 길이 만큼 한번 더 돌린다
            if (tmp[k] == word2[k]) // tmp의 글자와 word2의 글자가 같다면
              continue;    // continue
            else if (tmp[k] != word2[k]) // 한 글자라도 다르다면
              tmp_count++;  // tmp_count를 +1
          }
          if (tmp_count == 1) {  // 만약 tmp_count가 1이라면
            cout << *it << endl;  // 단어 출력
            count++;  // count +1
          }
          else {
            tmp_count = 0; // 1이 아니라면 tmp_count는 초기화 된다
          }
        }  
      }
    }
}

int main() {
  string wordFileName = "words.txt";  
  ifstream fin(wordFileName);  // 파일 읽기
  
  int word_size = 0;  // 단어 길이
  
  if (!fin) {
    cout << "파일 읽기 오류" << endl;
    return 0;
  }  // 만약 파일 읽지 못했다면, 오류 출력
  
  vector<string> v;
  
  fileRead(v, fin);  // 파일 읽기
  
  fin.close();
  
  while (true) { 
    cout << "검색할 단어:"; 
    string word;
    getline(cin, word);  // 단어 입력
    if (word == "exit")
      break;  // exit 입력하면 종료
    word_size = word.length();  // 단어 길이
    for (int j = 0; j < word_size; j++)
      search(v, word, word_size, j);  // 단어 길이 만큼 search 함수 실행
    
  }
  cout << "종료!" << endl;
}
