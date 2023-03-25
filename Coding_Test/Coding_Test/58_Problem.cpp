#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ����Ʈ�� ���̿켱 Ž��(DFS)
//			1
//		2		3
//	  4   5   6   7
// �� �׸��� ���� ����Ʈ���� ������ȸ�� ������ȸ�� �ۼ��Ͻÿ�.
// 
// ������ȸ : 1 2 4 5 3 6 7
// ������ȸ : 4 2 5 1 6 3 7
// ������ȸ : 4 5 2 6 7 3 1
//

void D1(int v)		// ���� ��ȸ
{
	if (v > 7) return;
	else
	{
		cout << v << ' ';
		D1(v * 2);
		D1(v * 2 + 1);
	}
}

void D2(int v)		// ���� ��ȸ
{
	if (v > 7) return;
	else
	{
		D2(v * 2);
		cout << v << ' ';
		D2(v * 2 + 1);
	}

}

void D3(int v)
{
	if (v > 7) return;
	else
	{
		D3(v * 2);
		D3(v * 2 + 1);
		cout << v << ' ';
	}
}

int No58()
{
	system_clock::time_point start = system_clock::now();

	D1(1);
	cout << endl;
	D2(1);
	cout << endl;
	D3(1);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No58();

	return 0;
}