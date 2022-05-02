#include <iostream>
#include <cmath>

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

	return 0;
}

