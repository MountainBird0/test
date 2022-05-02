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
		//head �� tail�� �����͸� �ʱ�ȭ;
		head = NULL;
		tail = NULL;
	}
	//ù��°�� node �߰�
	void addFrontNode(int n);
	//�������� node �߰�
	void addNode(int n);

	//node ����
	void insertNode(node *prevNode, int n);
	//node ����
	void deleteNode(node *prevNode);

	//ù��° ��� ��������
	node *getHead() {
		return head;
	}
	//LinkedList ���
	void display(node *head);
};

//ù��°�� node �߰�
void LinkedList::addFrontNode(int n) {
	node *temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//temp�� nextNode�� head
		temp->nextNode = head;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void LinkedList::addNode(int n) {
	node *temp = new node;

	//temp�� �����ʹ� n
	temp->data = n;
	//temp�� nextNode = NULL��
	temp->nextNode = NULL;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//���� ������ node�� nextNode�� temp
		tail->nextNode = temp;
		//������ node�� temp
		tail = temp;
	}
}

//node ����
void LinkedList::insertNode(node *prevNode, int n) {
	node *temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//temp�� nextNode ����
	//(���� �� �� node�� nextNode�� temp�� nextNode�� ����)
	temp->nextNode = prevNode->nextNode;

	//temp ����
	//temp���� node�� nextNode�� temp�� ����
	prevNode->nextNode = temp;
}

//node ����
void LinkedList::deleteNode(node *prevNode) {

	//������ node�� temp�� ����
	//(������ node�� 1�ܰ� �� node�� nextNode) 
	node *temp = prevNode->nextNode;

	//������ node�� ����
	//(������ node�� nextNode�� 1�ܰ� �� node�� nextNode�� ����)
	prevNode->nextNode = temp->nextNode;

	//temp ����
	delete temp;
}

//LinkedList ���
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
void add(int a, int b) // �Ǻ���ġ ����
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
void hanoi(int n, int from, int by, int to) // �����, ������, ������
{
	if (n == 1) // ��� Ż�� ����
	{
		std::cout << from << " " << to << std::endl;
	}
	else
	{
		hanoi(n - 1, from, to, by); // ���1�� n-1�� ������ ���2��
		std::cout << from << " " << to << std::endl;
		hanoi(n - 1, by, from, to); // ���2�� n-1�� ������ ���3����
	}
}

// https://rpatm.tistory.com/40
// �迭�� ���� ����
char stack[5];
int top = -1;

int isFull() // ��ȭ�������� �˻�
{
	if (top >= 4)
	{
		return 1;
	}
	return 0;
}
int isEmpty() // ����������� �˻�
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
	// �Ǻ���ġ
	int num1 = 1;
	int num2 = 1;
	add(num1, num2);

	// �ϳ���
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
	//1�߰�
	a.addNode(1);
	//2�߰�
	a.addNode(2);
	//3�߰�
	a.addNode(3);

	//display
	cout << "1,2,3�� LinkedList�� �߰�\n";
	a.display(a.getHead());

	//0�� ���� �տ� �߰�
	a.addFrontNode(0);

	//1�� �׹�°�� �߰�
	a.insertNode(a.getHead()->nextNode->nextNode, 1);
	cout << "0�� ù��°�� �߰�, 1�� �׹�°�� �߰�\n";
	a.display(a.getHead());

	//����° ��� ����
	a.deleteNode(a.getHead()->nextNode);

	//display
	cout << "����° ��带 ����\n";
	a.display(a.getHead());

	return 0;
}

