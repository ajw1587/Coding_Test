#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
#include <string>

using namespace std;
using namespace chrono;

// ���� ���� (Stack ����)
// A���ÿ��� ����� ������ B���÷� �����Ѵ�.
// �׷��� ���� �߰��� T���� �����ΰ� �־� ����� ������ ���� ������ ������ �� �ִ�.
// �����ο����� ������ ���� �� ���� �۾��� �մϴ�.
// 
// p �۾� : A���ÿ��� ���� ������ �����ο� �ִ´�.
// o �۾� : �����ο� ���� ���� �ֱ� ������ B���÷� ������.
// 
// ���� 2, 1, 3 ���� ��ȣ ������ A���ÿ��� ����ϴ���� B���ÿ��� T�����θ� �̿��Ͽ�
// 1, 2, 3 ������ ���� �� �� �ֽ��ϴ�.
// �� �۾� P, P, O, O, P, O ������ �۾��ϸ� B���ÿ� 1, 2, 3 ������ �����մϴ�.
// 1���� N���� ��ȣ�� ���� ������ A���ÿ��� � ������ ����ϵ�, B���ÿ� ��ȣ������ �����ϵ���
// �ϴ� ������ �۾��� ����Ͻÿ�.
// �Ұ����ϸ� impossible �̶�� ����Ͻÿ�.
// 
int No55()
{
	system_clock::time_point start = system_clock::now();

	int N = 3, check = 1;
	int idx = 0;
	vector<int> trains = { 2, 1, 3 };
	stack<int> buffer;
	string answer;

	for (int i = 0; i < N; i++)
	{
		buffer.push(trains[i]);
		answer.push_back('P');
		while (!buffer.empty() && buffer.top() == check)
		{
			buffer.pop();
			answer.push_back('O');
			check++;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No55();

	return 0;
}