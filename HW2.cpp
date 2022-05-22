#include <iostream>
#include <string>
using namespace std;

class Menu { // 화면 출력 및 키 입력 함수
    static int n; // 무슨 기능을 할지 입력 받은 숫자
public:
    static int main_menu(); // 삽입 삭제 모두보기 종료
};
int Menu::n = 0;  
int Menu::main_menu() {  // 메인 메뉴
    int n;  // 숫자를 입력할 int형 n 선언
    cout << "====================================" << endl;
    cout << "메뉴를 선택하세요[사각형 그리기(1), 원그리기(2), 선그리기(3), 전체지우기(4), 종료(0)] : " ;  // 메뉴 선택
    cin >> n;  // 메뉴를 선택할 숫자 입력
    return n;  // 선택한 숫자 return
}

class Shape { // 클래스 Shape
    int index; // 도형의 인덱스
    int s1, s2, e1, e2;
public:
    Shape(int i) { index = i; }
    Shape(int a, int b, int c, int d) { s1 = a; s2 = b; e1 = c; e2 = d; }   
    virtual void show() = 0; // 각 도형들의 출력함수를 구현하기 위해 순수 가상 함수 사용
    int getIndex() { return index; }  // index 반환하는 getIndex()
    int getInputs1() { return s1; }   // s1 반환  
    int getInputs2() { return s2; }   // s2 반환 
    int getInpute1() { return e1; }   // e1 반환 
    int getInpute2() { return e2; }   // e2 반환 
    void subIndex() { --index; }      // index를 하나 줄여주는 subIndex()
};

class Rect : public Shape {    // 클래스 Rect -> Shape 상속 
public:
    Rect(int index) : Shape(index) {}    // Rect : 생성자 Shape의 index
    Rect(int s1, int s2, int e1, int e2) : Shape(s1, s2, e1, e2) {}  // 입력값 생성자

    void show() {  // 출력
      cout << "사각형" << getIndex() << " 그리기 : 시작점 (" << getInputs1() << ", " << getInputs2() << ")," << " 끝점 (" << getInpute1() << ", " << getInpute2() <<")" << endl; }
}; // 사각형 좌표 출력


class Circle : public Shape {    // 클래스 Circle -> Shape 상속 
public:
    Circle(int index) : Shape(index) {} // Circle : 생성자 Shape의 index
    Circle(int s1, int s2, int e1, int e2) : Shape(s1, s2, e1, e2) {}  // 입력값 생성자

    void show() {  // 출력
      cout << "원" << getIndex() << " 그리기 : 시작점 (" << getInputs1() << ", " << getInputs2() << ")," << " 끝점 (" << getInpute1() << ", " << getInpute2() <<")" << endl; }
}; // 원 좌표 출력

class Line : public Shape {    // 클래스 Line -> Shape 상속 
public:
    Line(int index) : Shape(index) {}  // Line : 생성자 Shape의 index
    Line(int s1, int s2, int e1, int e2) : Shape(s1, s2, e1, e2) {}   // 입력값 생성자

    void show() {  // 출력
      cout << "선" << getIndex() << " 그리기 : 시작점 (" << getInputs1() << ", " << getInputs2() << ")," << " 끝점 (" << getInpute1() << ", " << getInpute2() <<")" << endl; }
}; // 선 좌표 출력

int main() {    // main 함수
    Shape *g[10];    // 총 10 개를 담을수 있는 포인터 g
    Shape *gg[10];   // 각각 rect, circle, line의 count를 한곳에 담을 포인터 gg
    int index = 1;   // 쌓여있는 도형들의 개수 세기 위해 선언
    int rindex = 1;  // 사각형 index
    int rcount = 0;  // 그린 사각형 개수 세기 위해 선언
    int cindex = 1;  // 원 index
    int ccount = 0;  // 그린 원 개수 세기 위해 선언
    int lindex = 1;  // 선 index
    int lcount = 0;  // 그린 선 개수 세기 위해 선언
    int s1, s2, e1, e2;  // s1, s2, e1, e2 선언
  
    for (;;) {
      int n = Menu::main_menu(); // 메인메뉴 출력
      if (n == 1) { // 사각형
        if (index > 5) {  // index가 5개를 초과한다면
          cout << "그릴 수 있는 최대 도형 개수 5개를 초과했습니다. 더 이상 도형을 그릴 수 없습니다." << endl; // 경고 출력 후
          cout << "모두 지운 후 다시 시도해 주십시오" << endl;
          break; // 프로그램 종료
        } // 그게 아니라면
        rcount++; // 먼저 rect의 count를 하나 up 하고,
        cout << "시작점 좌표를 입력하세요 : ";  // 시작점 좌표 입력
        cin >> s1 >> s2;
        cout << "끝점의 좌표를 입력하세요 : ";  // 끝점 좌표 입력
        cin >> e1 >> e2; 

        Rect* r = new Rect(rindex); //사각형 객체를 Shape 객체 배열에 저장 
        g[rindex] = r;  // g에 rindex를 저장
        gg[index] = r;  // gg에도 index를 저장
        ++rindex;  // rindex 1 증가
        ++index;   // index 1 증가

        cout << "========= 현재 그림판 상황 =========" << endl;  // 현재 그림판 상황
        cout << " 사각형 : " << rcount << "개, 원 : " << ccount << "개, 선 : " << lcount << "개" << endl;
        cout << "------------------------------------" << endl;  // 각각 도형 개수 출력
        for (int i = 1; i < index; ++i)
          gg[i]->show();       // 그린 도형들 다 출력
      }
      else if (n == 2) { // 원
        if (index > 5) {  // index가 5개를 초과한다면
          cout << "그릴 수 있는 최대 도형 개수 5개를 초과했습니다. 더 이상 도형을 그릴 수 없습니다." << endl;  // 경고 출력 후
          break;  // 프로그램 종료
        }
        ccount++;  // 먼저 circle의 count를 하나 up 하고,
        cout << "시작점 좌표를 입력하세요 : ";  // 시작점 좌표 입력
        cin >> s1 >> s2;
        cout << "끝점의 좌표를 입력하세요 : ";  // 끝점 좌표 입력
        cin >> e1 >> e2; 
        Circle* c = new Circle(cindex); //원 객체를 Shape 객체 배열에 저장
        g[cindex] = c;  // g에 cindex를 저장
        gg[index] = c;  // gg에도 index를 저장
        ++cindex;  // cindex 1 증가
        ++index;  // index 1 증가

        cout << "========= 현재 그림판 상황 =========" << endl;  // 현재 그림판 상황
        cout << " 사각형 : " << rcount << "개, 원 : " << ccount << "개, 선 : " << lcount << "개" << endl;  
        cout << "------------------------------------" << endl;  // 각각 도형 개수 출력
        for (int i = 1; i < index; ++i)
          gg[i]->show();  // 그린 도형들 다 출력
      }
      else if (n == 3) { // 라인 
        if (index > 5) {  // index가 5개를 초과한다면
          cout << "그릴 수 있는 최대 도형 개수 5개를 초과했습니다. 더 이상 도형을 그릴 수 없습니다." << endl;  // 경고 출력 후
          break;  // 프로그램 종료
        }
        lcount++;  // 먼저 Line의 count를 하나 up 하고,
        cout << "시작점 좌표를 입력하세요 : ";  // 시작점 좌표 입력
        cin >> s1 >> s2;
        cout << "끝점의 좌표를 입력하세요 : ";  // 끝점 좌표 입력
        cin >> e1 >> e2; 
        Line* l = new Line(lindex); //라인 객체를 Shape 객체 배열에 저장
        g[lindex] = l;  // g에 index를 저장
        gg[index] = l;  // gg에도 index를 저장
        ++lindex;  // lindex 1 증가
        ++index;  // index 1 증가

        cout << "========= 현재 그림판 상황 =========" << endl;  // 현재 그림판 상황
        cout << " 사각형 : " << rcount << "개, 원 : " << ccount << "개, 선 : " << lcount << "개" << endl;
        cout << "------------------------------------" << endl;  // 각각 도형 개수 출력
        for (int i = 1; i < index; ++i)
          gg[i]->show();  // 그린 도형들 다 출력
      }
      else if (n == 4) {  // 전체 지우기
        int i = 1;
        gg[i] = 0;
        index = 1;   // 다 초기화 시켜주고
        g[i] = 0;
        rindex = 1;
        cindex = 1;
        lindex = 1;
        rcount = 0;
        ccount = 0;
        lcount = 0;  // 각 도형들 카운트, 인덱스도 다 초기화 해준다
        cout << "모두 지웁니다." << endl;
      }
      else if (n == 0) {  // 종료 
        cout << "종료합니다." << endl;
        break;  // 종료
      }
      else cout << "잘못된 입력입니다." << endl;  // 그 이외는 잘못된 입력이라는 경고 출력
    }
}
