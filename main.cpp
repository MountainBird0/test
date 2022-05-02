#include <iostream>
#include <cmath>

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

	return 0;
}

