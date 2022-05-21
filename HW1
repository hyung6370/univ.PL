#include <iostream>
using namespace std;
class BaseArray {
  int capacity;    // 배열의 크기 cpapcity
  int *mem;        // int 배열을 만들기 위한 메모리 포인터
protected:
  BaseArray(int capacity=100) {
    this->capacity = capacity;
    mem = new int [capacity];    // 동적으로 배열 생성
  }
  ~BaseArray() { delete [] mem; }    // 동적으로 생성한 배열을 해제
  void put(int index, int val) { mem[index] = val; }  // 배열에 저장할 put
  int get(int index) { return mem[index]; }  // 배열에 저장할 get
  int getCapacity() { return capacity; }   // private에 접근할 수 없기 때문에, 이렇게 접근
  void queueResize();  // 큐 사이즈 조절할 Resize 함수
  void stackResize();  // 스택 사이즈 조절할 Resize 함수
};
class MyQueue : public BaseArray {
  int enindex = 0;
  int deindex = 0;  // enindex, deindex 0으로 초기화
public:
  MyQueue(int size) : BaseArray(size) {;}  // MyQueue 기본 생성자
  void enqueue(int n);    // 큐에 값 넣는 enqueue
  int capacity() { return getCapacity(); }  // capacity 기본 클래스에서 가져온다
  int length() { return deindex; }    //  큐 길이 -> 큐의 deindex 가져오면 된다
  int dequeue() { ++enindex; deindex--; return get(enindex); }
      // 큐에서 값 꺼내온다 -> enindex 늘려주고, deindex 줄인다 -> 그리고 리턴 enindex get 한다
};
class MyStack : public BaseArray {
  int top=0;  // 스택 top 0으로 초기화
public:
  MyStack(int size) : BaseArray(size) {;}  // MyStack 기본 생성자
  void push(int n);    // 스택에 추가할 push
  int capacity() { return getCapacity(); }  // capacity 기본 클래스에서 가져온다
  int length() { return top; }        // 스택 길이 -> 스택의 top 가져오면 된다
  int pop() { top--; return get(top); }  // 스택 팝 -> top -1 -> 리턴 top get 한다
};
void BaseArray::queueResize() {  // 동적으로 큐 사이즈 늘려줄 queueResize() 함수
  capacity *= 2;    // 기존의 capapcity 2배로 늘려준다
  BaseArray* newMem;    // 새로운 배열을 담을 newMem 생성
  newMem = (BaseArray *)malloc(2 * capacity * sizeof(*mem));
    // 스택과 마찬가지로 realloc을 사용해 구현해보았으나 에러남
    // malloc 사용해서 사이즈 2배로 늘려주고, 기존의 mem 복사해서 넣음
  free(newMem);  // 메모리 해제
}
void BaseArray::stackResize() {  // 동적으로 슽개 사이즈 늘려줄 stackResize() 함수
  capacity *= 2;    // 기존의 capapcity 2배로 늘려준다
  mem = (int *)realloc(mem, sizeof(int)*capacity);
    // realloc 사용해서 기존의 mem에 사이즈를 재할당
}
void MyQueue::enqueue(int n) {  // 큐 enqueue 함수
  if (deindex >= getCapacity()) {  // 큐의 deindex가 배열의 크기보다 크거나 같다면 
    cout << "Queue Full! -- 큐 용량 늘림!" << endl;  // 큐 꽉참
    queueResize();  // 큐 용량 자동으로 늘림 - queueReisze() 함수
  }
  deindex++;  // 꽉 차 있지 않다면, deindex를 하나 늘려주고,
  put(deindex, n);  // deindex에 값을 put 한다
}
void MyStack::push(int n) {    // 스택 push 함수 
  if (top == getCapacity()) {    // 스택 top이 배열의 크기와 같다면
    cout << "Stack Full! -- 스택 용량 늘림!" << endl;  // 스택 꽉참
    stackResize();  // 스택 용량 자동으로 늘림 - stackResize() 함수 
  }
  put(top, n); // 스택 top에 값 put 한다
  top++;  // top 사이즈 하나 늘려준다
}
int main() {  // 교수님이 제공해준 main 함수
  MyQueue mQ(3);
  MyStack mS(3);
  int n;
  cout << "5개의 정수를 입력하라>> ";
  for (int i = 0; i < 5; i++) {
    cin >> n;
    mQ.enqueue(n);  // 큐에 삽입
    mS.push(n);
  }
  cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
  cout << "스택의 용량: " << mS.capacity() << ", 스택의 크기: " << mS.length() << endl;
  cout << "큐의 원소를 2개 제거하여 출력한다>> ";
  cout << mQ.dequeue() << " ";
  cout << mQ.dequeue() << " ";
  cout << endl;
  cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
  cout << "5개의 정수를 입력하라>> ";
  for (int i = 0; i < 5; i++) {
    cin >> n;
    mQ.enqueue(n);
    mS.push(n);
  }
  cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
  cout << "스택의 용량: " << mS.capacity() << ", 스택의 크기: " << mS.length() << endl;
  cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
  while (mS.length() != 0) {
    cout << mS.pop() << " ";
}
cout << endl;
  cout << "스택의 용량: " << mS.capacity() << ", 스택의 크기: " << mS.length() << endl;
}
