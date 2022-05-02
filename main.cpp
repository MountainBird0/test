#include <iostream>
#include <cmath>

using namespace std;

// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kartmon&logNo=221510676043
struct node {
	int data;
	node *nextNode;
};

class LinkedList {
private:
	node *head;
	node *tail;
public:
	LinkedList() {
		//head 와 tail의 포인터를 초기화;
		head = NULL;
		tail = NULL;
	}
	//첫번째의 node 추가
	void addFrontNode(int n);
	//마지막의 node 추가
	void addNode(int n);

	//node 삽입
	void insertNode(node *prevNode, int n);
	//node 삭제
	void deleteNode(node *prevNode);

	//첫번째 노드 가져오기
	node *getHead() {
		return head;
	}
	//LinkedList 출력
	void display(node *head);
};

//첫번째의 node 추가
void LinkedList::addFrontNode(int n) {
	node *temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//temp의 nextNode는 head
		temp->nextNode = head;
		//head는 temp
		head = temp;
	}
}

//마지막의 node 추가
void LinkedList::addNode(int n) {
	node *temp = new node;

	//temp의 데이터는 n
	temp->data = n;
	//temp의 nextNode = NULL값
	temp->nextNode = NULL;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//현재 마지막 node의 nextNode는 temp
		tail->nextNode = temp;
		//마지막 node는 temp
		tail = temp;
	}
}

//node 삽입
void LinkedList::insertNode(node *prevNode, int n) {
	node *temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode 저장
	//(삽입 할 앞 node의 nextNode를 temp의 nextNode에 저장)
	temp->nextNode = prevNode->nextNode;

	//temp 삽입
	//temp앞의 node의 nextNode를 temp로 저장
	prevNode->nextNode = temp;
}

//node 삭제
void LinkedList::deleteNode(node *prevNode) {

	//삭제할 node를 temp에 저장
	//(삭제할 node의 1단계 전 node의 nextNode) 
	node *temp = prevNode->nextNode;

	//삭제할 node를 제외
	//(삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	prevNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;
}

//LinkedList 출력
void LinkedList::display(node *head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}


// 1, 1, 2, 3, 5, 8, 13, 21
void add(int a, int b) // 피보나치 수열
{
	if (b == 1)
	{
		std::cout << a << " " << b << " ";
	}
	int num3 = a + b;
	std::cout << num3 << " ";
	a = b;
	b = num3;
	if (num3 > 100)
	{
		return;
	}

	add(a, b);
}

// https://mimzz2.tistory.com/17
void hanoi(int n, int from, int by, int to) // 출발지, 경유지, 목적지
{
	if (n == 1) // 재귀 탈출 조건
	{
		std::cout << from << " " << to << std::endl;
	}
	else
	{
		hanoi(n - 1, from, to, by); // 기둥1의 n-1개 원판을 기둥2로
		std::cout << from << " " << to << std::endl;
		hanoi(n - 1, by, from, to); // 기둥2의 n-1개 원판을 기둥3으로
	}
}

// https://rpatm.tistory.com/40
// 배열로 스택 구현
char stack[5];
int top = -1;

int isFull() // 포화상태인지 검사
{
	if (top >= 4)
	{
		return 1;
	}
	return 0;
}
int isEmpty() // 공백상태인지 검사
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
void push(char data)
{
	if (!isFull())
	{
		top++;
		stack[top] = data;
	}
}
char pop()
{
	if (!isEmpty())
	{
		char temp = stack[top];
		top--;
		return temp;
	}
}
void print()
{
	if (!isEmpty())
	{
		for (int i =0; i <= top; i++)
		{
			std::cout << stack[i] << std:: endl;
		}
	}
}

int main()
{
	// 피보나치
	int num1 = 1;
	int num2 = 1;
	add(num1, num2);

	// 하노이
	int numcount = 3;
	hanoi(numcount, 1, 2, 3);

	push('a');
	push('b');
	push('c');
	print();
	pop();
	pop();
	print();


	LinkedList a;
	//1추가
	a.addNode(1);
	//2추가
	a.addNode(2);
	//3추가
	a.addNode(3);

	//display
	cout << "1,2,3을 LinkedList에 추가\n";
	a.display(a.getHead());

	//0을 제일 앞에 추가
	a.addFrontNode(0);

	//1을 네번째에 추가
	a.insertNode(a.getHead()->nextNode->nextNode, 1);
	cout << "0을 첫번째에 추가, 1을 네번째에 추가\n";
	a.display(a.getHead());

	//세번째 노드 삭제
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "세번째 노드를 삭제\n";
	a.display(a.getHead());

	return 0;
}

